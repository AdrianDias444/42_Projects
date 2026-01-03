#include "../header.h"

void pa(t_stack *stack_B, t_stack *stack_A)
{
    t_node *node_to_push;

    if(!stack_B || !stack_B->top)
        return ;
    node_to_push = ft_stack_pop(stack_B);
    ft_stack_push(stack_A, node_to_push);
    printf("pa\n");
}