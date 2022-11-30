%{
#include<math.h>
#define YYSTYPE int
#include<stdio.h>
int n = 1234577;
extern int yylineno;  // z lex-a
int yylex();
int yyerror(char*);
%}

%token VAL
%token MUL
%token DIV
%token POW
%token MIN
%token ADD
%token LNAW
%token PNAW
%token END
%token ERROR

%%
input:
    | input line
;
line: expa END	{ $$ = $1; printf(" %d\n",$$); }
    | error END	{ printf("\nBłąd.\n"); }
;
expa: expe		    { $$ = $1; }
    | expa ADD expe	{ $$ = (($1 + $3)%n); printf("+ "); }
    | expa MIN expe	{ if($1 - $3 < 0){$$ = n - ($1 - $3);}else {$$ = $1 - $3;}; printf("- "); }
;
expe: expu		    { $$ = $1; }
    | expe MUL expu	{ $$ = (($1 * $3) % n); printf("* "); }
    | expe DIV expu	{ $$ = $1 / $3; printf("/ "); }
;
expu: val           {$$ = $1;}
    | expu POW pow1 { if($3 == 0){$$ = 1;}; $$ = fastExp($1, $3, n); printf("^ ");}
;
val: VAL		        { $$ = $1; printf("%d ",$$); }
    | MIN VAL           { $$ = n - $2;}
    | LNAW expa PNAW	{ $$ = $2; }
;
pow1: val { $$ = $1; }
    | MIN val {$$ = n - $2 % (n - 1);}
;
%%

int yyerror(char *s)
{
    printf("%s\n",s);	
    return 0;
}

int fastExp(int b, int e, int m)
{
	int result = 1;
	if (1 & e)
		result = b;
	while (1) {
		if (!e) break;
		e >>= 1;
		b = (b * b) % m;
		if (e & 1)
			result = (result * b) % m;
	}
	return result;
}
int main()
{
    yyparse();
    printf("Przetworzono linii: %d\n",yylineno-1);
    return 0;
}
