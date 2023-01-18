#include "decl.h"
#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>

extern void indent(int indents);

struct decl *decl_create(char *ident, struct type *type, struct stmt *func_body, struct decl *var)
{
    struct decl *d = malloc(sizeof(*d));
    if (!d)
    {
        puts("[ERROR|FATAL] Could not allocate decl memory, exiting...");
        exit(EXIT_FAILURE);
    }

    d->ident = ident;
    d->type = type;
    d->func_body = func_body;
    d->var = var;
    d->next = NULL;
    d->symbol = NULL;

    return d;
}

void decl_print(struct decl *d, int indents, char *term)
{
    if (!d)
        return;

    indent(indents);
    printf("%s: ", d->ident);
    type_print(d->type);

    if (d->var)
    {
        fputs(" = ", stdout);
        expr_print(d->var);
    }

    if (d->func_body)
    {
        fputs(" = {\n", stdout);
        stmt_print_list(d->func_body, indents + 1, "\n");
        indent(indents);
        fputs("\n}", stdout);
    }
    else
        fputs(term, stdout);
}

void decl_print_list(struct decl *d, int indents, char *term, char *delim)
{
    if (!d)
        return;
    decl_print(d, indents, term);
    if (d->next)
        fputs(delim, stdout);
    decl_print_list(d->next, indents, term, delim);
}

int decl_resolve(struct decl *d, struct scope *sc, bool am_param, bool verbose)
{
    // ToDO/
}
