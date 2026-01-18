#include "../header.h"

t_node *ft_min_bellow(t_stack *stack_B, t_node *node_to_calc)
{
    t_node *current;
    t_node *min_bellow;
    t_node *first_min;

    first_min = NULL;
    current = stack_B->top;
    min_bellow = node_to_calc;
    while(current)
    {
        if(!first_min)
            if(current->nb < min_bellow->nb)
                min_bellow = current;
        if(first_min && current->nb < node_to_calc->nb && current->nb > min_bellow->nb)
            min_bellow = current;
        current = current->next;
    }
    return(min_bellow);
}