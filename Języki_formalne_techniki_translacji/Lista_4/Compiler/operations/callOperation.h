#ifndef CALLOPERATION_H
#define CALLOPERATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../codeGen/registerHandler.h"
#include "../codeGen/code.h"
#include "../expr.h"

char *get_reg(struct expr *expr);
struct expr *mul_call(struct CodeList *list, struct expr *expr);
struct expr *div_call(struct CodeList *list, struct expr *expr);
struct expr *mod_call(struct CodeList *list, struct expr *expr);

#endif
