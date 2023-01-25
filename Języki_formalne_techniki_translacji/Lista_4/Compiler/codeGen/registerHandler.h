#ifndef REGISTER_HANDLER_H
#define REGISTER_HANDLER_H

#include <stdio.h>

#define NUM_REGISTERS 4294967295

extern char *registers[NUM_REGISTERS];

char *get_register_varible(long long index);
void set_register_varible(char *varible);
unsigned long long get_register_index(char *varible);

#endif
