#include "stmtGen.h"

void stmt_generator(struct CodeList *list, struct stmt *s)
{
    if (!s)
        return;

    long long line_index = get_last_line_index(list);
    long long reg;

    switch (s->kind)
    {
    case STMT_EXPR:
        generate_from_expr(list, s->expr_list);
        break;
    case STMT_IF_ELSE:
        generate_if_code_from_expr(list, s);
        break;
    case STMT_WRITE:
        add_line(list, "PUT ", get_register_index(s->expr_list->data->ident_name));
        break;
    case STMT_READ:
        add_line(list, "GET ", get_register_index(s->expr_list->data->ident_name));
        break;
    case STMT_WHILE:
        generate_while_loop_code_from_expr(list, s);
        break;
    case STMT_REPEAT:
        generate_repeat_loop_code_from_expr(list, s);
        break;
    case STMT_HEAD:
        // copy_code_list(parameters, list);
        // TO DO
        break;
    }
    stmt_generator(list, s->next);
}