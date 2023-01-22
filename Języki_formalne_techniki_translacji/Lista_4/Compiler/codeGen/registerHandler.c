#define NUM_REGISTERS 16
int registers[NUM_REGISTERS];
int line_number = NUM_REGISTERS;

// Initialize all registers to 0
void init_registers()
{
    for (int i = 0; i < NUM_REGISTERS; i++)
    {
        registers[i] = 0;
    }
}

// Get the value of a register at a specific index
int get_register_value(int index)
{
    if (index < 0 || index >= NUM_REGISTERS)
    {
        printf("Error: Invalid register index\n");
        return -1;
    }
    return registers[index];
}

// Set the value of a register at a specific index
void set_register_value(int index, int value)
{
    if (index < 0 || index >= NUM_REGISTERS)
    {
        printf("Error: Invalid register index\n");
        return;
    }
    registers[index] = value;
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
void next_line()
{
    line_number++;
}