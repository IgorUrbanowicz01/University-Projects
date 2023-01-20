#include <stdio.h>
#include "parser.h"
#include "decl.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

typedef enum yytokentype token_t;

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int last_int_literal;
extern struct decl *ast;

extern int yyparse();

char *indent_space(int indents);
struct decl *scan_file(char *filename);
int parse_file(char *filename);
void print_ast(struct decl *ast);
int resolve_ast(struct decl *ast, bool verbose);
void process_cl_args(int argc, char **argv, bool *stages, char **to_compile);

/* stages */
int SCAN = 0,
    PARSE = 1,
    PPRINT = 2,
    RESOLVE = 3;

void usage(int return_code, char *called_as)
{
    printf(
        "usage: %s [options]\n"
        "\n"
        "Options:\n"
        "   -scan <file>    Scans <file> and outputs tokens encountered\n"
        "   -parse <file>   Scans <file> quietly and reports whether parse was successful\n"
        "   -print <file>   Scans and parses <file> quietly and outputs a nicely formatted version of the bminor program <file>\n"
        "   -resolve <file> Scans, parses, and builds AST for program <file> quietly, then resolves all variable references\n",
        called_as);
    exit(return_code);
}

int main(int argc, char **argv[])
{
    FILE *fin = fopen(argv[1], "r");

    /* scan */
    if (!fin)
    {
        printf("can't open file");
        exit(1);
    }

    yyin = fin;
    yyparse();
    print_ast(ast);

    return EXIT_SUCCESS;
}

void print_ast(struct decl *ast) { decl_print_list(ast, 0, ";", "\n"); }

/*int resolve_ast(struct decl *ast, bool verbose)
{
    struct scope *sc = scope_enter(NULL);
    int err_count = decl_resolve(ast, sc, false, verbose);
    scope_exit(sc);
    return err_count;
}

int parse_file(char *filename)
{
    yyin = fopen(filename, "r");
    if (!yyin)
    {
        printf("[ERROR|file] Could not open %s! %s\n", filename, strerror(errno));
        return 1;
    }
    // 0 for success, 1 for failure
    int to_return = yyparse();
    fclose(yyin);
    return to_return;
}

int scan_file(char *filename)
{
    /* Runs the flex-generated scanner on the file with name given by 'filename'
        - returns 1 on failure, 0 on success */

/* An array of strings, where token_strs[<token>] = "<token name as str>", where <token> is a value of the enum token_t and <token name as str> is the symbolic name given to <token> in the enum token_t. Substituted by the Makefile via sed, ensuring the array is up to date with token.h */
/*
    yyin = fopen(filename, "r");
    int t = yylex();

    return t;
}

void indent(int indents)
{
    for (int i = 0; i < indents; i++)
        fputs("\t", stdout);
}
*/