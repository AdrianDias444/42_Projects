#include "../header.h"

t_node *ft_return_max_sub_node(t_stack *stack)
{
    int i;
    int j;
    t_node *current;
    t_node *max_node;

    i = 0;
    j = ft_how_many_not_order(stack);
    current = stack->top;
    max_node = current;

    while(current && current->next && i < ft_lst_size(stack) - j)
    {
        if(max_node->nb < current->nb)
            max_node = current;
        current = current->next;
        i++;
    }
    return(max_node);
}