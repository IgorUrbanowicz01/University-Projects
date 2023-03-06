%{
#define YYSTYPE int
#include<stdio.h>
#include<string.h>
#include<math.h>
int yylex();
int yyerror(char*);
%}
%token <int> VAL
%token DOT
%token END
%token ERROR
%type <int> input line start error b
%type <int[]> l
%%
input:
    | input line
;
line: start END	{ $$ = $1; printf("\nWynyik = %d\n",$$); }
    | error END	{ printf("\nBłąd składni !\n"); }

start: l DOT l	{ $$ = $1; }
    | l	{ $$ = binToDec($1); }
;
l: l b   { $$ = $1 $2;}
| b     { $$ = (char)$1;}
;
b: VAL  { $$ = 1; printf("Input: %d", $1);}
;
%%
int yyerror(char *s)
{
    printf("%s\n",s);	
    return 0;
}
/*
int binToDec (char s[]){
    int resoult = 0;
    for (int i = strlen(s); 0>i; i--) {
        if (s[i] == 1) {
        resoult += pow(2, strlen(s)-i);
        }
    }
    return resoult;
}
*/

int binToDec (int s){
    int resoult = 0;
    for (int i = s; 0>i; i--) {
        resoult += pow(2, s);
    }
    return resoult;
}

int main()
{
    yyparse();
    return 0;
}
