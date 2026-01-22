#include "../header.h"


void ft_make_a_cicle(t_stack *stack_A, t_stack *stack_B)
{
    t_node *pivot;

    if(ft_lst_size(stack_A) + ft_lst_size(stack_B) > 110)
        pivot = ft_return_mid_mid(stack_A);
    else
        pivot = ft_return_mid(stack_A);
    while(ft_min_node(stack_A)->nb <= pivot->nb)
    {
        if(stack_A->top->nb <= pivot->nb)
        {
            if(!stack_B->top)
                pb(stack_A, stack_B);
            else if(!stack_B->top->next)
            {
                pb(stack_A, stack_B);
                if(stack_B->top->nb < stack_B->top->next->nb)
                    sb(stack_B);
            }
            else
                ft_insert_node(stack_A, stack_B);
        }
        else
        {
            if(ft_more_under_pivot(stack_A, pivot) == 1)
                ra(stack_A);
            if(ft_more_under_pivot(stack_A, pivot) == -1)
                rra(stack_A);

        }

    }
    while(stack_B->top != ft_max_node(stack_B))
    {
        if(ft_calc_cost(stack_B, ft_max_node(stack_B)) == 1)
            rb(stack_B);
        else
            rrb(stack_B);
    }
}