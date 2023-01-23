#include "registerHandler.h"
#include <string.h>

#define NUM_reg 32
char *reg[NUM_reg];
int line_number = 0;
int index_ = 2;

// Initialize all reg to 0
void init_reg()
{
    for (int i = 0; i < NUM_reg; i++)
    {
        reg[i] = 0;
        index_ = 2;
    }
}

// Get the value of a register at a specific index_
int get_register_value(int i)
{
    if (i < 0 || i >= NUM_reg)
    {
        printf("Error: Invalid register index_\n");
        return -1;
    }
    return reg[i];
}

// Set the name of varible to a register at a specific index_
void set_register_varible(char *varible)
{
    if (index_ < 0 || index_ >= NUM_reg)
    {
        printf("Error: Invalid register index_\n");
        return;
    }
    reg[index_] = varible;
    index_++;
}

int get_register_index_(char *varible)
{
    for (int i = 0; i < NUM_reg; i++)
    {
        if (strcmp(reg[i], varible) == 0)
        {
            return i;
        }
    }
    return -1;
}

/* END REGISTARES ============================ BEGIN LINE */

int get_line_number()
{
    return line_number;
}

// Function to set the current line number
void set_line_number(int new_line_number)
{
    line_number = new_line_number;
}

// Function to increment the current line number
void increment_counter()
{
    line_number++;
}