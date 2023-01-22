#include <stdio.h>
#include <stdlib.h>
#include "registerHandler.h"

// Structure for a single line of code
struct Line
{
    char *command;
    int arg1;
    struct Line *next;
};

// Structure for the linked list of lines of code
struct CodeList
{
    struct Line *head;
    struct Line *tail;
};

// Initialize an empty code list
void init_code_list(struct CodeList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

// Add a line of code to the code list
void add_line(struct CodeList *list, char *command, int arg1)
{
    struct Line *newLine = (struct Line *)malloc(sizeof(struct Line));
    newLine->command = command;
    newLine->arg1 = arg1;
    newLine->next = NULL;
    increment_counter();

    if (list->tail == NULL)
    {
        list->head = newLine;
        list->tail = newLine;
    }
    else
    {
        list->tail->next = newLine;
        list->tail = newLine;
    }
}

// Print the code list
void print_code_list(struct CodeList *list)
{
    struct Line *currentLine = list->head;
    while (currentLine != NULL)
    {
        printf("Command: %s, Arg1: %dn", currentLine->command, currentLine->arg1);
        currentLine = currentLine->next;
    }
}
