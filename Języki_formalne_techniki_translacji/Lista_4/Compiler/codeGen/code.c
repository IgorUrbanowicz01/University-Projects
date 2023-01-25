#include "code.h"
#include <stdio.h>
#include <stdlib.h>
#include "registerHandler.h"

// Initialize an empty code list
void init_code_list(struct CodeList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

// Add a line of code to the code list
void add_line(struct CodeList *list, char *command, char *arg1)
{
    struct Line *newLine = (struct Line *)malloc(sizeof(struct Line));
    newLine->command = command;
    newLine->arg1 = arg1;
    newLine->next = NULL;

    if (list->tail == NULL)
    {
        list->head = newLine;
        list->tail = newLine;
        newLine->line_number = 0;
    }
    else
    {
        newLine->line_number = get_last_line_index(list) + 1;
        list->tail->next = newLine;
        list->tail = newLine;
    }
}

long long get_last_line_index(struct CodeList *list)
{
    return list->tail->line_number;
}
// Print the code list
void print_code_list(struct CodeList *list)
{
    struct Line *currentLine = list->head;
    while (currentLine != NULL)
    {
        printf("Command: %s, Arg1: %sn", currentLine->command, currentLine->arg1);
        currentLine = currentLine->next;
    }
}

void copy_code_list(struct CodeList *a, struct CodeList *b)
{
    struct Line *currentLine = a->head;
    while (currentLine != NULL)
    {
        add_line(b, currentLine->command, currentLine->arg1);
        currentLine = currentLine->next;
    }
}
