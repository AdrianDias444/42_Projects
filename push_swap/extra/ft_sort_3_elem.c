#include "../header.h"

void ft_sort_3_elem(t_stack *stack_A, t_stack *stack_B)
{
    int i;

    i = 0;
    while(i < 3)
    {
        pb(stack_A, stack_B);
        i++;
    }
    if(ft_max_node(stack_B) == stack_B->top->next)
        sb(stack_B);
    else if(stack_B->top != ft_max_node(stack_B))
        rrb(stack_B);
    pa(stack_B, stack_A);
    if(stack_B->top != ft_max_node(stack_B))
        sb(stack_B);
    pa(stack_B, stack_A);
    pa(stack_B, stack_A);

}