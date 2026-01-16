#include "../header.h"


void ft_make_a_cicle(t_stack *stack_A, t_stack *stack_B)
{
    t_node *pivot;
    
    pivot = ft_return_mid(stack_A);
    printf("\npivot number is %d\n", pivot->nb);
    while (ft_min_node(stack_A)->nb <= pivot->nb)
    {
        if (stack_A->top->nb <= pivot->nb)
        {
            if(!stack_B->top || !stack_B->top->next)
                pb(stack_A, stack_B);
            if(stack_B->top && stack_B->top->next && stack_B->top->nb < stack_B->top->next->nb)
                sb(stack_B);

            if(stack_B->top->next &&  (stack_B->top->next->nb) < (stack_A->top->nb) < (stack_B->top->nb) && stack_A->top->nb <= pivot->nb)
            {
                rb(stack_B);
                pb(stack_A, stack_B);
                rrb(stack_B);
            }
            else
                rb(stack_B);        
        }
        else
            ra(stack_A);
    }
    while (ft_max_node(stack_B) != stack_B->top)
        rrb(stack_B);
}