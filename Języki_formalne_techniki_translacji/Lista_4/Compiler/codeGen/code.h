#ifndef CODE_H
#define CODE_H

struct Line
{
    int command;
    int arg1;
    int arg2;
    struct Line *next;
};

struct CodeList
{
    struct Line *head;
    struct Line *tail;
};

void init_code_list(struct CodeList *list);
void add_line(struct CodeList *list, char *command, int arg1);
void print_code_list(struct CodeList *list);
void copy_code_list(struct CodeList *a, struct CodeList *b);

#endif
