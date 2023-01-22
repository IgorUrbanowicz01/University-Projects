#include "../expr.h"
#include "registerHandler.h"
#include "code.h"

void generate_while_loop_code_from_expr(struct CodeList *list, struct expr *e, int line)
{
    switch (e->kind)
    {
    case EXPR_EQ:
        generateode_from_expr(list, e->data->operator_args->next, 0);
        generateode_from_expr(list, e->data->operator_args->next, 0);
        // Code to push JZERO instruction to jump to line if p0 == p1
        break;
    case EXPR_LT:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push LT instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 < p1
        break;
    case EXPR_LT_EQ:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push LTE instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 <= p1
        break;
    case EXPR_GT:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push GT instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 > p1
        break;
    case EXPR_GT_EQ:
        // Code to push GET instruction to load value of first argument into p0
        // Code to push GET instruction to load value of second argument into p1
        // Code to push GTE instruction to compare p0 and p1
        // Code to push JPOS instruction to jump to line if p0 >= p1
    }
}

void generateode_from_expr(struct CodeList *list, struct expr *e, int r)
{
    switch (e->kind)
    {
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