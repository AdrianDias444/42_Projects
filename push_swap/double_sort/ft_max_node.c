#include "../header.h"

t_node *ft_max_node(t_stack *stack)
{
    t_node *max_node;
    t_node *current;

    if(!stack || !stack->top)
        return (NULL);
    current = stack->top;
    max_node = current;
    while(current)
    {
        if(max_node->nb < current->nb)
            max_node = current;
        current = current->next;
    }
    return(max_node);
}