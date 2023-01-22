#include "exprGen.h"
#include "../expr.h"
#include "../stmt.h"
#include "registerHandler.h"
#include "code.h"

void generate_while_loop_code_from_expr(struct CodeList *list, struct stmt *s)
{
    int line_index = get_line_number();
    bool non_zero;
    switch (s->expr_list->kind)
    {
    case EXPR_EQ:
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        add_line(list, "STORE ", 1);

        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        add_line(list, "ADD ", 1);
        non_zero = false;

        break;
    case EXPR_NOT_EQ:
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        add_line(list, "STORE ", 1);

        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        add_line(list, "ADD ", 1);

        non_zero = true;

        break;
    case EXPR_LT:
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        non_zero = true;
        break;
    case EXPR_LT_EQ:
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        non_zero = false;
        break;
    case EXPR_GT:
        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        non_zero = true;
        break;
    case EXPR_GT_EQ:
        if (s->expr_list->data->operator_args->kind == EXPR_IDENT)
            add_line(list, "LOAD ", get_register_index(s->expr_list->data->operator_args->data->ident_name));
        else
        { /*Sometinh else*/
        }
        if (s->expr_list->data->operator_args->next->kind == EXPR_IDENT)
            add_line(list, "SUB ", get_register_index(s->expr_list->data->operator_args->next->data->ident_name));
        else
        { /*Sometinh else*/
        }
        non_zero = true;
    }

    add_line(list, "JUMP ", line_index);
}

void generate_if_code_from_expr(struct CodeList *list, struct stmt *s)
{
}

void generate_from_expr(struct CodeList *list, struct expr *e)
{
    switch (e->kind)
    {
    case EXPR_ASGN:

        break;
    case EXPR_ADD:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push EQ instruction to compare p0 and p1
        // Code to push JZERO instruction to jump to line if p0 == p1
        break;
    case EXPR_SUB:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push LT instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 < p1
        break;
    case EXPR_MUL:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push LTE instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 <= p1
        break;
    case EXPR_DIV:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push GT instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 > p1
        break;
    case EXPR_MOD:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push GTE instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 >= p1
        break;
    }
}