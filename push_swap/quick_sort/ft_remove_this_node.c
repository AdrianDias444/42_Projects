#include "../header.h"

t_node *ft_remove_this_node(t_stack *stack, t_node *node_to_del)
{
    t_node *current;
    t_node *previous;

    if(node_to_del == stack->top)
        return(ft_stack_pop(stack));

    if(node_to_del == ft_last_node(stack))
        return(ft_stack_pop_back(stack));

    current = stack->top->next;
    previous = stack->top;
    while(current)
    {
        if(node_to_del == current)
        {
            previous->next = current -> next;
            return(current);
        }
        current = current -> next;
        previous = previous -> next;
    }
    return(NULL);
}