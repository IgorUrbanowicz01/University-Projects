%option noyywrap
%option yylineno
%{
#include "calc_y.h"
int yylex();
%}

id [1-9][0-9]* 
%%
[ \t]+ 	;
{id} {yylval = atoi(yytext); return VAL;}
\-      { return MIN;}
\+      { return ADD; }
{id}\^{id}\^{id}   { return ERROR; }
\^	    { return POW; }
\*	    { return MUL; }
\/ 	    { return DIV; }
\(	    { return LNAW; }
\)	    { return PNAW; }
\n	    { return END; }
.	    { return ERROR; }

%%
