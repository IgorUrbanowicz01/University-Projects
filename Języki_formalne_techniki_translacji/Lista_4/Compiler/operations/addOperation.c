
#include <stdio.h>
#include <string.h>
#include "../codeGen/code.h"

void add_Operation_to_list(struct CodeList *list, char *operation)
{
    FILE *input = fopen(operation, "r");
    int nofl = get_last_line_index(list) + 1;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), input) != NULL)
    {
        char *p = buffer;
        char *first = strtok(p, " ");
        char *second = strtok(NULL, " ");
        if (second != NULL)
        {
            if (second[0] == '<')
            {
                int x = atoi(second + 1);
                sprintf(second, "%d", x + nofl);
            }
            add_line(list, first, second);
        }
    }
}