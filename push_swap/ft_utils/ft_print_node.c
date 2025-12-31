#include "../header.h"

void ft_print_node(t_node *first_node)
{
    t_node *current;

    
    current = first_node;
    while(current)
    {
        printf("%d\n", current->nb);  
        current = current->next;
    }
}