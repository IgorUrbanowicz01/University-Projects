#include "callOperation.h"

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

    default:
        printf("[FATAL|ERROR]WRONG EXPRESION PASSED");
        exit(1);
        break;
    }
}

void mul_call(struct CodeList *list, struct expr *expr)
{
    char *name = get_empty_register();
    strcat(name, "temp");
    set_register_varible(name);
    struct expr *new_expr = expr_create_identifier(name);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char *WYNIK = get_register_index(name);
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
    add_line(list, "STORE", WYNIK);
    expr_free_oper(expr->data->func_and_args);
    expr->kind = EXPR_IDENT;
    expr->data->ident_name = name;
}

void div_call(struct CodeList *list, struct expr *expr)
{
    char *name = get_empty_register();
    strcat(name, "temp");
    set_register_varible(name);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char *WYNIK = get_register_index(name);
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
    add_line(list, "LOAD", "3");
    add_line(list, "STORE", WYNIK);
    expr_free_oper(expr->data->func_and_args);
    expr->kind = EXPR_IDENT;
    expr->data->ident_name = name;
}

void mod_call(struct CodeList *list, struct expr *expr)
{
    char *name = get_empty_register();
    strcat(name, "temp");
    set_register_varible(name);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char *WYNIK = get_register_index(name);
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
    add_line(list, "STORE", WYNIK);
    expr_free_oper(expr->data->func_and_args);
    expr->kind = EXPR_IDENT;
    expr->data->ident_name = name;
}

void add_call(struct CodeList *list, struct expr *expr)
{
    char *name = get_empty_register();
    strcat(name, "temp");
    set_register_varible(name);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char *WYNIK = get_register_index(name);
    add_line(list, "LOAD", A);
    add_line(list, "ADD", B);
    add_line(list, "STORE", WYNIK);
    expr_free_oper(expr->data->func_and_args);
    expr->kind = EXPR_IDENT;
    expr->data->ident_name = name;
}

void sub_call(struct CodeList *list, struct expr *expr)
{
    char *name = get_empty_register();
    strcat(name, "temp");
    set_register_varible(name);
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    char *WYNIK = get_register_index(name);
    add_line(list, "LOAD", A);
    add_line(list, "SUB", B);
    add_line(list, "STORE", WYNIK);
    expr->kind = EXPR_IDENT;
    expr->data->ident_name = name;
    expr_free_oper(expr->data->func_and_args);
    expr_free_oper(expr->data->func_and_args->next);
}

void asg_call(struct CodeList *list, struct expr *expr)
{
    char *A = get_reg(expr->data->operator_args);
    char *B = get_reg(expr->data->operator_args->next);
    add_line(list, "LOAD", B);
    add_line(list, "STORE", A);
    expr_free_oper(expr);
}