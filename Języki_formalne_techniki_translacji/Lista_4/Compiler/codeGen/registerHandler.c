#include "registerHandler.h"

#define NUM_REGISTERS 32
int registers[NUM_REGISTERS];
int line_number = NUM_REGISTERS;
int index = 2;

// Initialize all registers to 0
void init_registers()
{
    for (int i = 0; i < NUM_REGISTERS; i++)
    {
        registers[i] = 0;
        index = 2;
    }
}

// Get the value of a register at a specific index
int get_register_value(int i)
{
    if (i < 0 || i >= NUM_REGISTERS)
    {
        printf("Error: Invalid register index\n");
        return -1;
    }
    return registers[i];
}

// Set the name of varible to a register at a specific index
void set_register_varible(char *varible)
{
    if (index < 0 || index >= NUM_REGISTERS)
    {
        printf("Error: Invalid register index\n");
        return;
    }
    registers[index] = varible;
    index++;
}

int get_register_index(char *varible)
{
    for (int i = 0; i < NUM_REGISTERS; i++)
    {
        if (strcmp(registers[i], varible) == 0)
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