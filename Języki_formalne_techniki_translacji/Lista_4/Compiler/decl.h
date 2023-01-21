

#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"

struct decl
{
	char *ident;
	struct type *type;
	struct stmt *func_body;
	struct decl *next_procedure;
	struct decl *next;
};

struct decl *decl_create(char *name, struct type *type, struct stmt *func_body, struct decl *next, struct decl *next_procedure);
void decl_print(struct decl *d, int indents, char *term);
void decl_print_list(struct decl *d, int indents, char *term, char *delim);
bool decl_find(struct decl *d, char *i_find);

struct scope;

#endif
