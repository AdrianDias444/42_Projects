#include "../header.h"

void ft_print_node(t_node *first_node)
{
    while(first_node)
    {
        printf("%d\n", first_node->nb);  
        first_node = first_node->next;
    }
}