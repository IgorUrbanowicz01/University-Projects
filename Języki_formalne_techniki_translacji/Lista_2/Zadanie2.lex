%s CODE
%s STRING_A
%s STRING_B
%s STRING_C
%s STRING_D

%%


<INITIAL>^#![^\r\n]*\r?\n?					ECHO; BEGIN(CODE);

<INITIAL,CODE>\"						BEGIN(STRING_A);
<INITIAL,CODE>\'						BEGIN(STRING_B);
<INITIAL,CODE>\"\"\"						BEGIN(STRING_C);
<INITIAL,CODE>\'\'\'						BEGIN(STRING_D);
<INITIAL,CODE>[ \t]*#.*\r?\n?					;

<STRING_A>\"					    BEGIN(CODE);
<STRING_B>\'						BEGIN(CODE);
<STRING_C>.                         ;
<STRING_C>\"\"\"					BEGIN(CODE);
<STRING_D>.                         ;
<STRING_D>\'\'\'					BEGIN(CODE);
<INITIAL>.							ECHO; BEGIN(CODE);

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
}