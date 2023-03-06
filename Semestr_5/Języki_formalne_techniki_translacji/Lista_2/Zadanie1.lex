

%{
#include <stdio.h>
#include <string.h>
int word_count = 0, line_count = 1;
int yywrap();
int yylex();
%}


%%

^[[:blank:]\\]*\n       {};
^[[:blank:]]+           {};
[[:blank:]]+$           {};
[ \t]+                  {putchar( ' ' );};
[^ \t\n]+               {ECHO; ++word_count;};
\n                      {ECHO; ++line_count;};

%%

int yywrap() {
	return 1;
}

int main( int argc, char **argv )
{  
        ++argv, --argc;
        if ( argc > 0 )
                yyin = fopen( argv[0], "r" );
        else
                yyin = stdin;
        yylex();
        printf("\n# of words %d \n# of lines %d\n",word_count,line_count);
}

