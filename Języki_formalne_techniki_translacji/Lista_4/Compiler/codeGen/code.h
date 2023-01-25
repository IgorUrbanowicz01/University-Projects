#ifndef CODE_H
#define CODE_H

struct Line
{
    int command;
    char *arg1;
    long long line_number;
    struct Line *next;
};

struct CodeList
{
    struct Line *head;
    struct Line *tail;
};

void init_code_list(struct CodeList *list);
void add_line(struct CodeList *list, char *command, char *arg1);
void print_code_list(struct CodeList *list);
void copy_code_list(struct CodeList *a, struct CodeList *b);
ong long get_last_line_index(struct CodeList *list);

#endif
