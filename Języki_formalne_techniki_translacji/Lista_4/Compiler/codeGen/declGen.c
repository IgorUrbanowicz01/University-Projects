#include "declGen.h"

void decl_generator(struct CodeList *list, struct decl *d)
{

    stmt_generator(list, d->func_body);
}