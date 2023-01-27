#include <stdio.h>
#include <stdlib.h>
#include "addOperation.h"
#include "callOperation.h"

int main(int argc, char *argv[])
{
    struct CodeList *list = (struct CodeList *)malloc(sizeof(struct CodeList));
    init_code_list(list);
    add_line(list, "JUMP", "116");
    add_Operation_to_list(list, "divide");
    add_Operation_to_list(list, "mod");
    add_Operation_to_list(list, "mul");
    add_line(list, "SET", "10");
    add_line(list, "STORE", "11");
    add_line(list, "SET", "25");
    add_line(list, "STORE", "12");
    set_register_varible(list, "10");
    set_register_varible(list, "25");
    print_registers();
    struct expr *mul = expr_create_oper(EXPR_MOD, expr_create_identifier("10"), expr_create_identifier("25"));
    struct expr *temp = mul_call(list, mul);
    struct expr *div = expr_create_oper(EXPR_MOD, temp, expr_create_identifier("25"));
    sub_call(list, div);
    add_line(list, "PUT", "3");
    add_line(list, "HALT", NULL);
    print_code_list(list);
}