#include "../header.h"


void ft_make_a_cicle(t_stack *stack_A, t_stack *stack_B)
{
    t_node *pivot;

    pivot = ft_return_mid(stack_A);

    while(ft_min_node(stack_A)->nb <= pivot->nb)
    {
        while(stack_B->top && stack_B->top->next && ft_max_node(stack_B) != stack_B->top)
        {
            if(ft_calc_cost(stack_B, ft_max_node(stack_B)) == 1)
                rb(stack_B);
            else
                rrb(stack_B);
        }
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
            {
                int find_place = ft_find_place(stack_B, stack_A->top);
                while(ft_min_node(stack_B)->nb < stack_A->top->nb && stack_A->top->nb < ft_max_node(stack_B)->nb && !(stack_B->top->nb < stack_A->top->nb && stack_A->top->nb < ft_last_node(stack_B)->nb))
                {
                    if(find_place == 1)
                        rb(stack_B);
                    else
                        rrb(stack_B);
                }
                pb(stack_A, stack_B);
            }
        }
        else
            ra(stack_A);

    }
    while(stack_B->top != ft_max_node(stack_B))
    {
        if(ft_calc_cost(stack_B, ft_max_node(stack_B)) == 1)
            rb(stack_B);
        else
            rrb(stack_B);
    }
}