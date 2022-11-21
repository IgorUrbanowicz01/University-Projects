

%option noyywrap
%{
#include <stdio.h>
#include <string.h>
int word_count = 0, line_count = 1;
%}


%%

^[[:blank:]\\]*\n       {};
^[[:blank:]]+           {};
[ \t]+                  {putchar( ' ' );};
[[:blank:]]+$           {};
[^ \t\n]+               {ECHO; ++word_count;};
\n                      {ECHO; ++line_count;};

%%

int main( int argc, char **argv )
{  
        ++argv, --argc;
        if ( argc > 0 )
                yyin = fopen( argv[0], "r" );
        else
                yyin = stdin;
        yylex();
        printf("# of words %d \n# of lines %d\n",word_count,line_count);
}

