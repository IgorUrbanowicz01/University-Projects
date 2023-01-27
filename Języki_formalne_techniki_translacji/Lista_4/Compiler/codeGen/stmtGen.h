#ifndef STMT_GENERATOR_H
#define STMT_GENERATOR_H

#include "../stmt.h"
#include "registerHandler.h"
#include "code.h"
#include "exprGen.h"

void stmt_generator(struct CodeList *list, struct stmt *s);

#endif
