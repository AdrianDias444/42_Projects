#include "../header.h"


int ft_find_place(t_stack *stack, t_node *node_to_insert)
{
    t_node *current;
    int i;

    current = stack->top;
    i = 0;
    while(current && current->next)
    {
        if(current->next->nb < node_to_insert->nb && node_to_insert->nb < current->nb)
            if(ft_lst_size(stack)/2 > i)
                return(1);
        i++;
        current = current->next;
    }
    return(-1);
}