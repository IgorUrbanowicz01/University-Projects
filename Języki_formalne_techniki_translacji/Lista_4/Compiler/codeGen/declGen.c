#include "declGen.h"

void decl_generator(struct CodeList *list, struct decl *d)
{
    stmt_generator(list, d->func_body);
}

void decl_resolve_int(struct CodeList *list, struct decl *d)
{
    if (!d)
        return;
    stmt_resolve_int(list, d->func_body);
    decl_resolve_int(list, d->next_procedure);
}

void decl_generator_procedure(struct CodeList *list, struct decl *d)
{
    // stmt_generator_procedure(list, d->func_body);
    decl_generator_procedure(list, d->next_procedure);
}