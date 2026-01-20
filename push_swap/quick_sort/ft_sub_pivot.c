#include "../header.h"


t_node *ft_sub_pivot(t_stack *stack)
{
    t_stack new_stack;
    t_node *pivot;

    if(!stack)
        return (NULL);
    new_stack = ft_sub_stack(stack);
    pivot = ft_return_mid(&new_stack);
    return(pivot);
}