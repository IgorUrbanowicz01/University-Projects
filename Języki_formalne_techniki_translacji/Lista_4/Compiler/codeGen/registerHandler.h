#ifndef REGISTER_HANDLER_H
#define REGISTER_HANDLER_H

#include <stdio.h>

#define NUM_REGISTERS 1024

extern int registers[NUM_REGISTERS];
extern int line_number;

void init_registers();
int get_register_varible(int index);
void set_register_varible(char *varible);
int get_register_index(char *varible);

#endif
