#include "../header.h"

t_stack ft_sub_stack(t_stack *stack)
{
    int i;
    t_stack new_stack;

    i = 0;
    new_stack = ft_dup_stack(stack);
    while(i < ft_how_many_not_order(stack))
    {
        ft_stack_pop_back(&new_stack);
        i++;
    }
    return(new_stack);
    
}