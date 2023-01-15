
%{
#include <stdio.h>
#include "decl.h"
#include "stmt.h"
#include "expr.h"
//#include "param_list.h"
#include "type.h"
#include <stdlib.h>
#include <string.h>

//#define YYSTYPE struct decl *

extern char *yytext;
extern int last_int_literal;
extern int yylex();
extern int yyerror( char *str );
//extern char *clean_string(char *string, char delim);
struct decl *ast;

%}

%token PROCEDURE
%token IS
%token VAR
%token X_BEGIN
%token END
%token PROGRAM
%token IF
%token THEN
%token ELSE
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%token REPEAT
%token UNTIL
%token READ
%token WRITE
%token LPR
%token RPR
%token ASSIGN
%token COMMA
%token SEMICOLON
%token EQ
%token NEQ
%token GT
%token LT
%token LEQ
%token GEQ
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token IDENT
%token INT_LIT
%token SCAN_ERR
%token TOKEN_EOF


%union {
    struct decl *decl;
    struct stmt *stmt;
    struct expr *expr;
    //struct param_list *param_list;
    struct type *type;
    char *ident;
}

%type <decl>        program decl param_comma_list procedures_decl main
%type <stmt>        stmt maybe_stmts  if_stmt write_stmt while_stmt repeat_stmt
%type <expr>        read_stmt expr expr1 expr3 expr4 expr5 expr6 func_call atom expr_commdecla_list
/* %type <param_list>  param_comma_list, maybe_param_comma_list, expr_comma_list, maybe_expr_comma_list */
%type <ident>       ident

%%

program : procedures_decl main
        { ast = $2; return 0; }
        ;
/* END PROGRAM ================================= BEGIN PROCEDURE */

procedures_decl : procedures_decl PROCEDURE ident LPR param_comma_list RPR IS VAR decl X_BEGIN maybe_stmts END
            { $$ = decl_create($3, type_create(TYPE_FUNCTION, NULL, $5), NULL, $11, $9); }
            | procedures_decl PROCEDURE ident LPR param_comma_list RPR IS X_BEGIN stmt END
            { $$ = decl_create($3, type_create(TYPE_FUNCTION, NULL, $5), NULL, $9, NULL); }
            |
            { $$ = NULL; }
            ;

param_comma_list : ident 
      { $$ = decl_create($1, type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); }
      | ident param_comma_list
      { $$ = decl_create($1, type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); $$->next = $2; }
      ;


/* END PROCEDURE ================================= BEGIN DECLARATIONS */

decl : decl COMMA ident 
      { $$  = decl_create($3, type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); $$->next = $1; }
      | ident 
      { $$  = decl_create($1, type_create(TYPE_INTEGER, NULL, NULL), NULL, NULL, NULL); }
      ;



/* END DECLARATIONS ============================ BEGIN MAIN */

main : PROGRAM IS VAR decl X_BEGIN maybe_stmts END
      {$$ = decl_create(NULL, type_create(TYPE_FUNCTION,  NULL, NULL), NULL, $6, $4);}
      |PROGRAM IS X_BEGIN maybe_stmts END
      {$$ = decl_create(NULL, type_create(TYPE_FUNCTION,  NULL, NULL), NULL, $4, NULL);}
      ;
 
/* END MAIN ============================ BEGIN STATEMENTS */

stmt : expr
      { $$ = stmt_create(STMT_EXPR, NULL, $1, NULL, NULL); }
      | if_stmt
      { $$ = $1; }
      | read_stmt
      { $$ = $1; }
      | write_stmt
      { $$ = $1; }
      | while_stmt
      { $$ = $1; }
      | repeat_stmt
      { $$ = $1; }
     ;


if_stmt : IF expr THEN stmt ELSE stmt ENDIF
        { $4->next = $6; $$ = stmt_create(STMT_IF_ELSE, NULL, $2, $4, $6); }
        | IF  expr THEN stmt ENDIF
        { $$ = stmt_create(STMT_IF_ELSE, NULL, $2, $4, NULL); }
        ;

read_stmt : READ expr SEMICOLON
      { $$ = stmt_create(STMT_READ, NULL, $2, NULL, NULL);}
      ;

write_stmt: WRITE expr SEMICOLON
      { $$ = stmt_create(STMT_WRITE, NULL, $2, NULL, NULL);}
      ;

while_stmt: WHILE expr DO maybe_stmts ENDWHILE
      { $$ = stmt_create(STMT_WHILE, NULL, $2, $4, NULL);}
      ;

repeat_stmt: REPEAT maybe_stmts UNTIL expr SEMICOLON 
      { $$ = stmt_create(STMT_REPEAT, NULL, $4, $2, NULL);}
      ;


maybe_stmts : /* empty */
            { $$ = NULL; }
            | stmt maybe_stmts
            { $1->next = $2; $$ = $1; }
            ;

/* END STATEMENTS ============================ BEGIN EXPRESSIONS */

/* expression: can be treated as a single value */
expr : expr6
     { $$ = $1; }
     ;

/* assignment: = */
expr6: expr5 ASSIGN expr6 SEMICOLON
      { $$ = expr_create_oper(EXPR_ASGN, $1, $3); }
      | expr5
      { $$ = $1; }
      ;

/* comparisons: < <= > >= == != */
expr5 : expr5 LT expr4
      { $$ = expr_create_oper(EXPR_LT, $1, $3); }
      | expr5 LEQ expr4
      { $$ = expr_create_oper(EXPR_LT_EQ, $1, $3); }
      | expr5 GT expr4
      { $$ = expr_create_oper(EXPR_GT, $1, $3); }
      | expr5 GEQ expr4
      { $$ = expr_create_oper(EXPR_GT_EQ, $1, $3); }
      | expr5 EQ expr4
      { $$ = expr_create_oper(EXPR_EQ, $1, $3); }
      | expr5 NEQ expr4
      { $$ = expr_create_oper(EXPR_NOT_EQ, $1, $3); }
      | expr4
      { $$ = $1; }
      ;

/* binary add/sub: + - */
expr4 : expr4 ADD expr3
      { $$ = expr_create_oper(EXPR_ADD, $1, $3); }
      | expr4 SUB expr3
      { $$ = expr_create_oper(EXPR_SUB, $1, $3); }
      | expr3
      { $$ = $1; }
      ;

/* mult/div/mod: * / % */
expr3 : expr3 MUL expr1
      { $$ = expr_create_oper(EXPR_MUL, $1, $3); }
      | expr3 DIV expr1
      { $$ = expr_create_oper(EXPR_DIV, $1, $3); }
      | expr3 MOD expr1
      { $$ = expr_create_oper(EXPR_MOD, $1, $3); }
      | expr1
      { $$ = $1; }
      ;

/* grouping: () [] f() */
expr1 : func_call
      { $$ = $1; }
      | atom
      { $$ = $1; }
      ;

/* atom: lowest form of expression */
atom : ident
     { $$ = expr_create_identifier($1); }
     | INT_LIT
     { $$ = expr_create_integer_literal(last_int_literal); }
     ;

ident: IDENT
     { char *s = strdup(yytext);
       if (!s){
           fprintf(stdout, "[ERROR|internal] Failed to allocate space for duping identifier.\n");
           exit(EXIT_FAILURE);
       }
       $$ = s;
     }
     ;


/* function call: <function name>(<arg list>) */
/* use expr1 instead of ident at the head of this call so that I can have a function return a function, and then access that function */
func_call: expr1 LPR expr_commdecla_list RPR
         { $$ = expr_create_function_call($1, $3); }
         ;


expr_commdecla_list: expr
               { $$ = $1; }
               | expr COMMA expr_commdecla_list
               { $1->next = $3; $$ = $1; }
               ;
%%

int yyerror( char *str )
{
    printf("parse error: %s\n",str);
    return 0;
}
