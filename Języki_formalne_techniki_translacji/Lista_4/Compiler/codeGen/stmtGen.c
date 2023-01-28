#include "stmtGen.h"

extern struct decl *procedure;

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
        if (is_parameter(s->expr_list->data->ident_name))
        {
            // TO DO//
            add_line(list, "PUT ", get_register_index(s->expr_list->data->ident_name));
        }
        else
        {
            add_line(list, "PUT ", get_register_index(s->expr_list->data->ident_name));
        }

        break;
    case STMT_READ:
        if (is_parameter(s->expr_list->data->ident_name))
        {
            add_line(list, "GET ", get_register_index(s->expr_list->data->ident_name));
        }
        else
        {
            add_line(list, "GET ", get_register_index(s->expr_list->data->ident_name));
        }
        break;
    case STMT_WHILE:
        generate_while_loop_code_from_expr(list, s);
        break;
    case STMT_REPEAT:
        generate_repeat_loop_code_from_expr(list, s);
        break;
    case STMT_HEAD:
        generate_stmt_head(list, s);
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

void generate_stmt_head(struct CodeList *list, struct stmt *s)
{
    char buffer[20];
    char buffer1[20];
    struct decl *current = procedure;
    while (current != NULL)
    {
        if (strcmp(current->ident, s->decl->ident) == 0)
        {
            generate_parameters_code_stmt(list, s->decl->type->params, current->next);
            unsigned long long line = get_last_line_index(list) + 4;
            unsigned long long line_procedure_start = get_line_procedure(current->ident);
            sprintf(buffer1, "%llu", line_procedure_start);
            sprintf(buffer, "%llu", line);
            add_line(list, "SET", buffer);
            add_line(list, "STORE", "11");
            add_line(list, "JUMP", buffer1);
            return;
        }
        current = current->next_procedure;
    }
    printf("ERROR|INTERNAL undeclerd procedure: %s", s->decl->ident);
    exit(1);
}

void generate_parameters_code_stmt(struct CodeList *list, struct decl *d, struct decl *param)
{
    if (!d)
        return;
    if (!param)
        return;
    char *A = get_register_index(d->ident);
    char *B = get_register_index(param->ident);
    add_line(list, "SET", A);
    add_line(list, "LOAD", B);
    generate_parameters_code_stmt(list, d->next, param->next);
}

void stmt_change_name(char *name, struct stmt *s)
{
    if (!s)
        return;

    switch (s->kind)
    {
    case STMT_EXPR:
        expr_change_name(name, s->expr_list);
        break;
    case STMT_IF_ELSE:
        expr_change_name(name, s->expr_list);
        stmt_change_name(name, s->body);
        stmt_change_name(name, s->else_body);
        break;
    case STMT_WRITE:
        break;
    case STMT_READ:

        break;
    case STMT_WHILE:
        expr_change_name(name, s->expr_list);
        stmt_change_name(name, s->body);
        break;
    case STMT_REPEAT:
        expr_change_name(name, s->expr_list);
        stmt_change_name(name, s->body);
        break;
    case STMT_HEAD:
        break;
    default:
        printf("ERROR|INTERNAL wrong kind of statment");
        break;
    }
    stmt_change_name(name, s->next);
}