#include "../header.h"


void ft_insert_node(t_stack *stack_A, t_stack *stack_B)
{
    int find_place = ft_find_place(stack_B, stack_A->top);
    if(stack_A->top->nb > ft_min_node(stack_B)->nb)
    {
        while(ft_min_bellow(stack_B, stack_A->top)->nb != stack_B->top->nb)
        {
            if(find_place == 1)
                rb(stack_B);
            else
                rrb(stack_B);
        }
    }
    else
    {
        while(stack_B->top->nb != ft_max_node(stack_B)->nb)
        {
            if(ft_calc_cost(stack_B, ft_max_node(stack_B)) == 1)
                rb(stack_B);
            else
                rrb(stack_B);
        }
    }
    pb(stack_A, stack_B);
}



//while(ft_min_node(stack_B)->nb < stack_A->top->nb && stack_A->top->nb < ft_max_node(stack_B)->nb && !(stack_B->top->nb < stack_A->top->nb && stack_A->top->nb < ft_last_node(stack_B)->nb))
