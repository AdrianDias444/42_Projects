#include "../header.h"

void ft_remake_cicle(t_stack *stack_A, t_stack *stack_B)
{
    t_node *pivot;
    int count;

    pivot = ft_return_mid(stack_A);
    printf("\npivot number is %d\n", pivot->nb);
    while(ft_min_node(stack_A)->nb <= pivot->nb)
    {
        if(stack_A->top->nb <= pivot->nb)
        {
            count = 0;
            while(stack_A->top->nb <= stack_B->top->nb)
            {
                rb(stack_B);
                count ++;
            }
            pb(stack_A, stack_B);
            while(count > 0)
            {
                rrb(stack_B);
                count--;
            }
        }
        else
            ra(stack_A);
    }
}