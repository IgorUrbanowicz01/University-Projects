#include "registerHandler.h"

struct Node *head = NULL;

void set_register_varible(char *varible)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->varible = strdup(varible);
    new_node->next = NULL;
    if (head == NULL)
    {
        new_node->reg = 11;
        head = new_node;
    }
    else
    {
        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        new_node->reg = current->reg + 1;
        current->next = new_node;
    }
}

char *get_register_index(char *varible)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->varible, varible) == 0)
        {
            char reg_str[20];
            snprintf(reg_str, 20, "%lld", current->reg);
            return strdup(reg_str);
        }
        current = current->next;
    }
    printf("ERROR| cant find verible %s\n", varible);
    return strdup("-1");
}

void print_registers()
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("Register index: %llu, Variable: %s\n", current->reg, current->varible);
        current = current->next;
    }
}

char *get_empty_register()
{
    if (head == NULL)
    {
        return strdup("11");
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    char reg_str[20];
    snprintf(reg_str, 20, "%lld", current->reg + 1);
    return strdup(reg_str);
}