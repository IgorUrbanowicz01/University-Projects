#include "callOperation.h"
#include "../expr.h"
#include "../codeGen/registerHandler.h"

/*
1 <--- line where divide starts
44 <--- line where mod starts
87 <--- line where mul starts
116 <--- line where mul ENDS
*/

char *get_reg(struct expr *expr)
{

    switch (expr->kind)
    {
    case EXPR_IDENT:
        return get_register_index(expr->data->ident_name);
        break;

    case EXPR_INT_LIT:
        return get_register_index(expr->data->ident_name);
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

struct expr *add_call(struct CodeList *list, struct expr *expr)
{
    struct expr *new_expr = expr_create(EXPR_TEMP, NULL);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    add_line(list, "LOAD", A);
    add_line(list, "ADD", B);
    add_line(list, "STORE", "3");
    expr_free_oper(expr);
    return new_expr;
}

struct expr *sub_call(struct CodeList *list, struct expr *expr)
{
    struct expr *new_expr = expr_create(EXPR_TEMP, NULL);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    add_line(list, "LOAD", A);
    add_line(list, "SUB", B);
    add_line(list, "STORE", "3");
    expr_free_oper(expr);
    return new_expr;
}