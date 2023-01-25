#include <stdio.h>
#include <stdlib.h>
#include "addOperation.c"

int main(int argc, char *argv[])
{
    // check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // open input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    struct CodeList *list = (struct CodeList *)malloc(sizeof(struct CodeList));
    init_code_list(list);
    add_Operation_to_list(list, "divide");
    print_code_list(list);

    return 0;
}