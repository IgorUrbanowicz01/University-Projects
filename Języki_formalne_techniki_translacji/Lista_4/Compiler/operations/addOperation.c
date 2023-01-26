
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../codeGen/code.h"

void add_Operation_to_list(struct CodeList *list, FILE *input)
{
    add_line(list, "SET", "0");
    add_line(list, "STORE", "3");
    unsigned long long nofl = get_last_line_index(list) + 1;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), input) != NULL)
    {
        char *p = buffer;
        char *first = strtok(p, " ");
        char *second = strtok(NULL, " ");
        if (second != NULL)
        {
            int len = strcspn(second, "\n");
            memset(second + len, 0, 1);
            if (second[0] == '<')
            {
                int x = atoi(second + 1);
                sprintf(second, "%lld", x + nofl);
            }
            add_line(list, first, second);
        }
        else
        {
            int len = strcspn(first, "\n");
            memset(first + len, 0, 1);
            add_line(list, first, NULL);
        }
    }
}