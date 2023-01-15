#ifndef TYPE_H
#define TYPE_H

#include "decl.h"
#include "expr.h"

typedef enum
{
	TYPE_INTEGER,
	TYPE_FUNCTION,
} type_t;

struct type
{
	type_t kind;
	struct decl *params;
	struct type *subtype;
};

struct type *type_create(type_t kind, struct type *subtype, struct decl *params);
void type_print(struct type *t);

#endif
