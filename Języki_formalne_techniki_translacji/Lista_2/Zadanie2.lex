%{
#include <stdio.h>

int yylex();
int yywrap();
%}

%x COMMENT1
%x COMMENT2

%%
\' {BEGIN(COMMENT1); ECHO;}
<COMMENT1>{
    \\\' ECHO;
    \'  {ECHO; BEGIN(INITIAL);}
    .   ECHO;
}
\" {BEGIN(COMMENT2); ECHO;}
<COMMENT2>{
    \\\" ECHO;
    \"  {ECHO; BEGIN(INITIAL);}
    .   ECHO;
}
#.*\n  printf("\n");
%%

int yywrap() {
    return 1;
}

int main(int argc, char** argv) {
     ++argv, --argc;
        if ( argc > 0 )
                yyin = fopen( argv[0], "r" );
        else
                yyin = stdin;
        yylex();
}