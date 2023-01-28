#ifndef DECLGENERATOR_H
#define DECLGENERATOR_H

#include "../decl.h"
#include "code.h"
#include "stmtGen.h"

void decl_generator(struct CodeList *list, struct decl *d);
void decl_generator_procedure(struct CodeList *list, struct decl *d);
void decl_resolve_int(struct CodeList *list, struct decl *d);

#endif
