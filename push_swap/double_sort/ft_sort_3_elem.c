#include "../header.h"

void ft_sort_3_elem(t_stack *stack_A)
{

    if(ft_max_node(stack_A) == stack_A->top)
        ra(stack_A);
    if(ft_max_node(stack_A) == stack_A->top->next)
        rra(stack_A);
    if(stack_A->top->nb > stack_A->top->next->nb)
        sa(stack_A);
}