%option noyywrap
%option yylineno
%{
#include "bool-calc_y.h"
int yylex();
%}
%%
[ \t]+ 	;
1 	{ yylval = 1; return VAL; }
0 	{ yylval = 0; return VAL; }
\.  { return DOT; }
\n	{ return END; }
.	{ return ERROR; }
%%
