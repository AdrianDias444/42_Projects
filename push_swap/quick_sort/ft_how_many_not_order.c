#include "../header.h"

int ft_how_many_not_order(t_stack *stack)
{
    int i;
    t_stack new_stack;
    
    i = 0;
    new_stack = ft_dup_stack(stack);
    while(ft_max_node(&new_stack) == ft_last_node(&new_stack))
    {
        ft_stack_pop_back(&new_stack);
        i++;
    }
    return(i);
}