#include <stdio.h>
#include <stdlib.h>
#include "addOperation.h"

int main(int argc, char *argv[])
{
    struct CodeList *list = (struct CodeList *)malloc(sizeof(struct CodeList));
    init_code_list(list);
    add_Operation_to_list(list, "divide");
    add_Operation_to_list(list, "mod");
    add_Operation_to_list(list, "mul");
    print_code_list(list);
}