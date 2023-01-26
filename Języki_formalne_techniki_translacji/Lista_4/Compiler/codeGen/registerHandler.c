#include "registerHandler.h"
#include <string.h>

#define NUM_reg 4294967295
char *reg[NUM_reg];
int index_ = 11;

// Get the value of a register at a specific index_
char *get_register_value(long long i)
{
    if (i < 0 || i >= NUM_reg)
    {
        printf("Error: Invalid register index_\n");
        return "-1";
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

unsigned long long get_register_index(char *varible)
{
    for (unsigned long long i = 11; i < NUM_reg; i++)
    {
        if (strcmp(reg[i], varible) == 0)
        {
            return i;
        }
    }
    return -1;
}