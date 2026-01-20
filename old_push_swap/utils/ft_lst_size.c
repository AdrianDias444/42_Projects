#include "../header.h"

int ft_lst_size(t_stack *stack)
{
    t_node *current;
    int i;

    if(!stack || !stack->top)
        return(0);
    current = stack->top;
    i = 0;
    while(current)
    {
        i++;
        current = current -> next;
    }
    return(i);
}