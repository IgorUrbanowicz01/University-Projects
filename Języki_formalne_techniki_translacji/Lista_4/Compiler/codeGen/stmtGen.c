#include "stmtGen.h"

void stmt_generator(struct CodeList *list, struct stmt *s)
{
    if (!s)
        return;

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
    default:
        printf("ERROR|INTERNAL wrong kind of statment");
        break;
    }
    stmt_generator(list, s->next);
}

void stmt_resolve_int(struct CodeList *list, struct stmt *s)
{
    if (!s)
        return;

    switch (s->kind)
    {
    case STMT_EXPR:
        resolve_expr_int(s->expr_list);
        expr_add_int(list, s->expr_list);
        break;
    case STMT_IF_ELSE:
        resolve_expr_int(s->expr_list);
        expr_add_int(list, s->expr_list);
        stmt_resolve_int(list, s->body);
        stmt_resolve_int(list, s->else_body);

        break;
    case STMT_WRITE:
        break;
    case STMT_READ:

        break;
    case STMT_WHILE:
        resolve_expr_int(s->expr_list);
        expr_add_int(list, s->expr_list);
        stmt_resolve_int(list, s->body);
        break;
    case STMT_REPEAT:
        resolve_expr_int(s->expr_list);
        expr_add_int(list, s->expr_list);
        stmt_resolve_int(list, s->body);
        break;
    case STMT_HEAD:
        break;
    default:
        printf("ERROR|INTERNAL wrong kind of statment");
        break;
    }
    stmt_resolve_int(list, s->next);
}