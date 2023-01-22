#ifndef REGISTER_HANDLER_H
#define REGISTER_HANDLER_H

#include <stdio.h>

#define NUM_REGISTERS 16

extern int registers[NUM_REGISTERS];
extern int line_number;

void init_registers();
int get_register_varible(int index);
void set_register_varible(char *varible);
int get_line_number();
void set_line_number(int new_line_number);
void increment_counter();
int get_register_index(char *varible);

#endif
