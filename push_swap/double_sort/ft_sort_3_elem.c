#include "../header.h"

void ft_sort_3_elem(t_stack *stack_A, t_stack *stack_B)
{
    t_node *top_A;

    pb(stack_A, stack_B);
    if(stack_A->top->nb > stack_A->top->next->nb)
        sa(stack_A);
    pa(stack_B, stack_A);
    top_A = stack_A->top;
    if(top_A->nb > top_A->next->nb && top_A->nb > top_A->next->next->nb)
        ra(stack_A);
    top_A = stack_A->top;
    if(top_A->nb > top_A->next->nb)
        sa(stack_A);
}