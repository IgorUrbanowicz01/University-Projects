#ifndef REGISTER_HANDLER_H
#define REGISTER_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "code.h"

struct Node
{
    unsigned long long reg;
    char *varible;
    struct Node *next;
};

// extern char *registers[NUM_REGISTERS];

char *get_register_varible(unsigned long long reg);
void set_register_varible(struct CodeList *list, char *varible);
char *get_register_index(char *varible);
char *get_empty_register();
void print_registers();

#endif
