

%option yylineno
%option nounput
%option noinput

%{
    #include <stdbool.h>
    #include "parser.h"

    char *clean_string(char *string, char skip);
    
    int last_int_literal;

%}

/* DEFINITIONS */
/* interesting regexs placed here along with custom classes since the rules section is necessarily cluttered */
DIGIT       [0-9]
LOWER       [a-z]
UPPER       [A-Z]
LETTER      {LOWER}|{UPPER}
WHITESPACE  [ \r\n\t]
IDENT       ({LETTER}|_)({LETTER}|{DIGIT}|_)*
INT_LIT     {DIGIT}+

%%
\[[^]]*\]			{/* consume whitespace */}
{WHITESPACE}        {/* consume whitespace */}
<<EOF>>                     { return TOKEN_EOF; }

"PROCEDURE"         { return PROCEDURE; }
"IS"                { return IS; }
"VAR"               { return VAR; }
"BEGIN"             { return X_BEGIN; }
"END"               { return END; }
"PROGRAM"           { return PROGRAM; }
"IF"                { return IF; }
"THEN"              { return THEN; }
"ELSE"              { return ELSE; }
"ENDIF"             { return ENDIF; }
"WHILE"             { return WHILE; }
"DO"                { return DO; }
"ENDWHILE"          { return ENDWHILE; }
"REPEAT"            { return REPEAT;}
"UNTIL"             { return UNTIL; }
"READ"              { return READ; }
"WRITE"             { return WRITE; }

"("                     { return LPR; }
")"                     { return RPR; }

":="                    {  printf("ASSIGN");return ASSIGN;}
","                     { return COMMA; }
";"                     { return SEMICOLON; }

"!="                    { return NEQ; }
"="                     { return EQ; }
"<"                     { return LT; }
">"                     { return GT; }
"<="                    { return LEQ; }
">="                    { return GEQ; }

"+"                     { return ADD; }
"-"                     { return SUB; }
"*"                     { return MUL; }
"/"                     { return DIV; }
"%"                     { return MOD; }


{IDENT}                     { return yyleng <= 256 ? IDENT : SCAN_ERR; }
{INT_LIT}                   {
                            last_int_literal = atoi(yytext);
                            return INT_LIT;
                            }

.                           { return SCAN_ERR; }

%%

/* additional code */

int yywrap(){ return 1; }

