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
}

void generate_repeat_loop_code_from_expr(struct CodeList *list, struct stmt *s)
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
}

void generate_from_expr(struct CodeList *list, struct expr *e)
{
    struct stmt *procedure = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
    switch (e->kind)
    {

        break;
    case EXPR_ADD:
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(1), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        break;
    case EXPR_SUB:
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        break;
    case EXPR_MUL:
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(1), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r3"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r4"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(1), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r3"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r4"), NULL, NULL);
        break;
    case EXPR_DIV:
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(1), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r3"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r4"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(1), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r3"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r4"), NULL, NULL);
        break;
    case EXPR_MOD:
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r4"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, expr_create_identifier("r1"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(1), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r3"), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal(0), NULL, NULL);
        procedure->expr_list = stmt_create(STMT_WHILE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_integer_literal, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_IF_ELSE, NULL, NULL, NULL, NULL);
        procedure->expr_list = stmt_create(STMT_EXPR, NULL, expr_create_identifier("r2"), NULL, NULL);
        break;
    }
}