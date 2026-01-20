#include "../header.h"

t_node *ft_min_bellow(t_stack *stack_B, t_node *node_to_calc)
{
    t_stack new_stack;

    if(!stack_B->top || !stack_B->top->next)
        return (NULL);

    new_stack = ft_dup_stack(stack_B);
    if(node_to_calc->nb == ft_min_node(&new_stack)->nb)
        return (NULL);
    while(ft_max_node(&new_stack)->nb >= node_to_calc->nb)
        ft_remove_this_node(&new_stack, ft_max_node(&new_stack));

    return(ft_max_node(&new_stack));
}