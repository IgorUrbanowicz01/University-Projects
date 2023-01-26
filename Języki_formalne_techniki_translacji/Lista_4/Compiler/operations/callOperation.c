
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../codeGen/code.h"
#include "../codeGen/registerHandler.h"
#include "../expr.h"

/*
1 <--- line where divide starts
44 <--- line where mod starts
87 <--- line where mul starts
116 <--- line where mul ENDS
*/

char *get_reg(struct expr *expr)
{
    unsigned long long value;
    char buffer[20] = {0};
    char *new_string = malloc(strlen(buffer) + 1);

    switch (expr->kind)
    {
    case EXPR_IDENT:
        value = get_register_index(expr->data->ident_name);
        sprintf(buffer, "%llu", value);
        strcpy(new_string, buffer);
        return new_string;
        break;

    case EXPR_INT_LIT:
        value = get_register_index(expr->data->ident_name);
        sprintf(buffer, "%llu", value);
        strcpy(new_string, buffer);
        return new_string;
        break;
    case EXPR_TEMP:
        return "3";
        break;

    default:
        printf("[FATAL|ERROR]WRONG EXPRESION PASSED");
        exit(1);
        break;
    }
}

struct expr *mul_call(struct CodeList *list, struct expr *expr)
{
    struct expr *new_expr = expr_create(EXPR_TEMP, NULL);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char buffer[20];
    add_line(list, "LOAD", A);
    add_line(list, "STORE", "1");
    add_line(list, "LOAD", B);
    add_line(list, "STORE", "2");
    unsigned long long line = get_last_line_index(list) + 4;
    sprintf(buffer, "%llu", line);
    add_line(list, "SET", buffer);
    add_line(list, "STORE", "8");
    add_line(list, "JUMP", "87");
    expr_free_oper(expr);
    return new_expr;
}

struct expr *div_call(struct CodeList *list, struct expr *expr)
{
    struct expr *new_expr = expr_create(EXPR_TEMP, NULL);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char buffer[20];
    add_line(list, "LOAD", A);
    add_line(list, "STORE", "1");
    add_line(list, "LOAD", B);
    add_line(list, "STORE", "2");
    unsigned long long line = get_last_line_index(list) + 4;
    sprintf(buffer, "%llu", line);
    add_line(list, "SET", buffer);
    add_line(list, "STORE", "8");
    add_line(list, "JUMP", "1");
    expr_free_oper(expr);
    return new_expr;
}

struct expr *mod_call(struct CodeList *list, struct expr *expr)
{
    struct expr *new_expr = expr_create(EXPR_TEMP, NULL);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char buffer[20];
    add_line(list, "LOAD", A);
    add_line(list, "STORE", "1");
    add_line(list, "LOAD", B);
    add_line(list, "STORE", "2");
    unsigned long long line = get_last_line_index(list) + 4;
    sprintf(buffer, "%llu", line);
    add_line(list, "SET", buffer);
    add_line(list, "STORE", "8");
    add_line(list, "JUMP", "44");
    expr_free_oper(expr);
    return new_expr;
}
