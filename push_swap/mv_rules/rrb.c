#include "../header.h"

void rrb(t_stack *stack)
{
    t_node *last_node;

    if(!stack || !stack->top)
        return ;

    last_node = ft_stack_pop_back(stack);
    ft_stack_push(stack, last_node);
    printf("rrb\n");
}