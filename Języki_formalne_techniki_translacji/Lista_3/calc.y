%{
#include<math.h>
#define YYSTYPE int
#include<stdio.h>
#include <stdlib.h>
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

%left ADD MIN
%left MUL DIV
%right POW

%%
input:
    | input line
;
line: MIN expa END	{ $$ = n-$2; printf("\n= %d \n",$$); }
    | expa END	{ if($1 == -1){$$ = -1;}else{ $$ = $1; printf("\n= %d\n",$$);}; }
    | error END	{ printf("Błąd.\n"); }
;
expa: expe		    { $$ = $1; }
    | expa ADD expe	{ $$ = (($1 + $3)%n); printf("+ "); }
    | expa MIN expe	{ if($1 - $3 < 0){$$ = ($1 + (n - $3)%(n));}else {$$ = $1 - $3;}; printf("- "); }
;
expe: expu		    { $$ = $1; }
    | expe MUL expu	{ $$ = (($1 * $3) % n); printf("* "); }
    | expe DIV expu	{ $$ = divide($1, $3, n); printf("/ "); }
;
expu: val           {$$ = $1;}
    | expu POW val1 { if($3 == 0){$$ = 1;}; $$ = fastExp($1, $3, n); printf("^ ");}
;
val: MIN VAL           { $$ = n-$2; printf("%d ", $$);}
    | VAL		        { $$ = $1; printf("%d ",$$); }
    | LNAW expa PNAW	{ $$ = $2; }
;


//
pow1: expe1		    {if($1 == -1){$$ = -1;}else{ $$ = $1;}; }
    | pow1 ADD expe1	{ $$ = (($1 + $3)%n); printf("+ "); }
    | pow1 MIN expe1	{ if($1 - $3 < 0){$$ = (($1 - $3)%(n-1)+n-1)%(n-1);}else {$$ = $1 - $3;}; printf("- ", $$, $1, $2); }
;
expe1: val1	    { $$ = $1; }
    | expe1 MUL val1 { $$ = (($1 * $3) % (n-1)); printf("* "); }
    | expe1 DIV val1 { if(divide($1, $3, (n-1)) == -1){$$ = -1;} else {$$ = divide($1, $3, (n-1));}; printf("/ "); }
;

val1: MIN VAL           { $$ = n - 1 - $2; printf("%d ", $$);}
    | VAL		        { $$ = $1; printf("%d ",$$); }
    | LNAW pow1 PNAW	{ $$ = $2; }
;
%%

int yyerror(char *s)
{
    printf("%s\n",s);	
    return 0;
}

int divide(int a, int b, int p) {
    int x, y;
    long long inv;
    int g = extendedEuclideanAlgorithm(b, p, &x, &y);
    if (g != 1)
        inv = -1;
    else
        inv = (x%p + p)%p;
    a = a%p;
    if (inv == -1){
        printf("> %d nie jest odwracalne modulo %d\n", b, p);
        return -1;
    }
    return (inv * a)%p;
}

int fastExp(long int b, long int e, long int m)
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

int extendedEuclideanAlgorithm(int a, int b, int *x, int *y) {
        if (a == 0){
            *x = 0, *y = 1;
            return b;
        }
        int x1, y1;
        int gcd = extendedEuclideanAlgorithm(b%a, a, &x1, &y1);
        *x = y1 - (b/a) *x1;
        *y = x1;
        return gcd;
}

int main()
{
    yyparse();
    printf("Przetworzono linii: %d\n",yylineno-1);
    return 0;
}
