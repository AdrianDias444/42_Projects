#include "../header.h"


void ft_make_a_cicle(t_stack *stack_A, t_stack *stack_B)
{
    t_node *pivot;
    int count;

    pivot = ft_return_mid(stack_A);
    //printf("/nPivot number is %d\n", pivot->nb);
    while(ft_min_node(stack_A)->nb <= pivot->nb)
    {
        count = 1;
        while(stack_B->top && stack_B->top->next && ft_max_node(stack_B) != stack_B->top)
            rrb(stack_B);
        if(stack_A->top->nb <= pivot->nb)
        {
            if(!stack_B->top)
                pb(stack_A, stack_B);
            else if(!stack_B->top->next && count == 1)
            {
                pb(stack_A, stack_B);
                if(stack_B->top->nb < stack_B->top->next->nb)
                    sb(stack_B);
            }
            else
            {
                while(ft_min_node(stack_B)->nb < stack_A->top->nb && stack_A->top->nb < ft_max_node(stack_B)->nb && !(stack_B->top->nb < stack_A->top->nb && stack_A->top->nb < ft_last_node(stack_B)->nb))
                    rb(stack_B);
                pb(stack_A, stack_B);
            }
        }
        else
            ra(stack_A);

    }
    while(stack_B->top != ft_max_node(stack_B))
        rrb(stack_B);
}