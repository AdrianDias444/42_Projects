#include "../header.h"

void rb(t_stack *stack)
{
    t_node *first_node;

    if(!stack || !stack->top || !stack->top->next)
        return ;
    first_node = ft_stack_pop(stack);
    ft_stack_push_back(stack, first_node);
    printf("rb\n");
}