%{
#include<stdio.h>
#include <stdbool.h>

int yywrap();
int yylex();
int lines_count = 0;
int words_count = 0;

bool allow_shebang = true;
void shebang_done() {
	allow_shebang = false;
}

%}

%x string_mode
%x documentation

%%

#!.*\n							{if(allow_shebang) {ECHO; shebang_done();};};
.?((\"\")|(\'\'))							{printf("%s", yytext);};
[^\\][\"\']{3}					{printf("%s", yytext); BEGIN(documentation);};
<documentation>[^\\][\"\']{3}	{printf("%s", yytext); BEGIN(0);};
[^\\][\"\']						{printf("%s", yytext); BEGIN(string_mode);};
<string_mode>[^\\][\"\']		{printf("%s", yytext); BEGIN(0);};
#.*\n?							{};

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
        printf("# of words %d \n# of lines %d\n",word_count,line_count);
}
