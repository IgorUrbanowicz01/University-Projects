#include "../stmt.h"
#include "registerHandler.h"
#include "code.h"
#include "exprGen.h"

void generateode_from_expr(struct CodeList *list, struct CodeList *parameters, struct stmt *s)
{
    if (!s)
        return;

    int line_index = get_line_number();

    switch (s->kind)
    {
    case STMT_EXPR:
        generate_from_expr(list, s->expr_list);
        break;
    case STMT_IF_ELSE:
        generate_if_code_from_expr(list, s);
        break;
    case STMT_READ:
        add_line(list, "PUT ", get_register_index(s->expr_list->data->ident_name));
        break;
    case STMT_WRITE:
        add_line(list, "GET ", get_register_index(s->expr_list->data->ident_name));
        break;
    case STMT_WHILE:
        generate_while_loop_code_from_expr(list, s);
        break;
    case STMT_REPEAT:
        generate_repeat_loop_code_from_expr(list, s);
        break;
    case STMT_HEAD:
        copy_code_list(parameters, list);
        break;
    }
    generateode_from_expr(list, parameters, s->next);

    /*struct stmt addstmtAdd(struct stmt s)
    {
        struct stmt new_stmt = stmt_create(STMT_IF_ELSE, NULL, NULL);
                                   s->next =
            return new_stmt
    struct stmt *stmt_create(stmt_t kind, struct decl *decl, struct expr *expr_list, struct stmt *body, struct stmt *else_body);
    }*/
}