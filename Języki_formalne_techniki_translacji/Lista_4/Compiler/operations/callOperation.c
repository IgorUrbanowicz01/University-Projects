
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../codeGen/code.h"
#include "../expr.h"

/*
1 <--- line where divide starts
44 <--- line where mod starts
87 <--- line where mul starts
116 <--- line where mul ENDS
*/

void mul_call(struct Codelist *list, struct expr *expr)
{
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
}

void div_call(struct Codelist *list, struct expr *expr)
{
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
}

void mod_call(struct Codelist *list, struct expr *expr)
{
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
}

char *get_reg(struct expr *expr)
{
    switch (expr->kind)
    {
    case EXPR_IDENT:
        char buffer[20];
        unsigned long long value = get_register_index(expr->data->ident_name);
        sprintf(buffer, "%llu", value);
        return buffer;
        break;

    case EXPR_INT_LIT:
        char buffer[20];
        unsigned long long value = get_register_index(expr->data->ident_name);
        return sprintf(buffer, "%llu", value);
        break;

    default:
        printf("[FATAL|ERROR]WRONG EXPRESION PASSED");
        exit(1);
        break;
    }
}