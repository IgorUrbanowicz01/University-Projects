#include "exprGen.h"
#include "../expr.h"
#include "../stmt.h"
#include "../operations/callOperation.h"
#include "registerHandler.h"
#include "code.h"

void generate_while_loop_code_from_expr(struct CodeList *list, struct stmt *s)
{
    int line_index = get_last_line_index(list);
    bool non_zero;
    switch (s->expr_list->kind)
    {
    case EXPR_EQ:
        break;
    case EXPR_NOT_EQ:

        break;
    case EXPR_LT:
        break;
    case EXPR_LT_EQ:
        break;
    case EXPR_GT:
        break;
    case EXPR_GT_EQ:

        break;
    default:
        printf("ERROR|Wrong while expresion\n");
        return;
        break;
    }

    // add_line(list, "JUMP ", line_index);
}

void generate_if_code_from_expr(struct CodeList *list, struct stmt *s)
{
    /*TO DO*/
}

void generate_repeat_loop_code_from_expr(struct CodeList *list, struct stmt *s)
{
    /*TO DO*/
}

void generate_from_expr(struct CodeList *list, struct expr *e)
{
    if (!e)
        return;
    switch (e->kind)
    {
    case EXPR_IDENT:
        return;
        break;
    case INT_LIT:
        return;
        break;
    case EXPR_ADD:
        generate_from_expr(list, e->data->func_and_args);
        generate_from_expr(list, e->data->func_and_args->next);
        add_call(list, e);
        break;
    case EXPR_SUB:
        generate_from_expr(list, e->data->func_and_args);
        generate_from_expr(list, e->data->func_and_args->next);
        sub_call(list, e);
        break;
    case EXPR_MUL:
        generate_from_expr(list, e->data->func_and_args);
        generate_from_expr(list, e->data->func_and_args->next);
        mul_call(list, e);
        break;
    case EXPR_DIV:
        generate_from_expr(list, e->data->func_and_args);
        generate_from_expr(list, e->data->func_and_args->next);
        div_call(list, e);
        break;
    case EXPR_MOD:
        generate_from_expr(list, e->data->func_and_args);
        generate_from_expr(list, e->data->func_and_args->next);
        mod_call(list, e);
        break;
    case EXPR_ASGN:
        generate_from_expr(list, e->data->func_and_args->next);
        asg_call(list, e);
        break;
    default:
        printf("ERROR|Wrong operation expresion\n");
        return;
        break;
    }
}