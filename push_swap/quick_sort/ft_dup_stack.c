#include "../header.h"

t_stack ft_dup_stack(t_stack *stack)
{
    t_node *current;
    t_node *current_to_add;
    t_stack new_stack;

    ft_stack_init(&new_stack);
    current = stack->top;
    while(current)
    {
        current_to_add = ft_create_node(current->nb);
        ft_stack_push_back(&new_stack, current_to_add);
        current = current -> next;
    }
    return(new_stack);
}