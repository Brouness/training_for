#include "struct.h"

node    *ft_new_node(void *ptr)
{
    node *pointer;
    pointer = malloc(sizeof(node));
    if (!pointer)
        return (NULL);
    pointer->data = ptr;
    pointer->next = NULL;
    return (pointer);
}
void    ft_add_node(node *a, node *b)
{
    if (!a)
        return ;
    a->next = b;
    b->next = NULL;
}
int main()
{
    node *a = ft_new_node("500");
    node *b = ft_new_node("600");
    node *c = ft_new_node("700");
    ft_add_node(a, b);
    ft_add_node(b, c);
    int count = ft_count(a);
    printf("the number of nodes is : %d\n", count);
    printf("Data entered in the list :\n");
    int o = 0;

    node *jump;
    jump  = a;
    while (jump != NULL)
    {
        printf("Data = %s ", jump->data);
        jump = jump->next;
    }
    node *kjump = ft_last_node(a);
    printf("\nThe data of the last node is : %s", kjump->data);
    printf("\n| NOW WE ARE GOING TO PRINT THE LIST REVERSED |");
    int i = 0;
    jump = a;
    node *last = NULL;
    while (jump != NULL)
    {
        last = ft_last_node(jump)
        
    }
}