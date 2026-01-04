#include "../header.h"

void ft_double_sort(t_stack *stack_A, t_stack *stack_B)
{
    t_node *min_node;
    t_node *max_node;
    int min_calc;
    int max_calc;

    while(stack_A->top && ft_lst_size(stack_A) > 1)
    {
        max_node = ft_max_node(stack_A);
        min_node = ft_min_node(stack_A);

        min_calc = ft_calc_cost(stack_A, min_node);
        max_calc = ft_calc_cost(stack_A, max_node);
        while(stack_A->top != min_node)
        {
            if(min_calc == 1)
                ra(stack_A);
            if(min_calc == -1)
                rra(stack_A);
        }
        pb(stack_A, stack_B);
        
        while(stack_A->top != max_node)
        {
            if(max_calc == 1)
                ra(stack_A);
            if(max_calc == -1)
                rra(stack_A);
        }
        pb(stack_A, stack_B);
    }
    pb(stack_A, stack_B);
    while(stack_B->top)
    {
        pa(stack_B, stack_A);
        if(stack_A->top->next)
            if(stack_A->top->nb > stack_A->top->next->nb)
                ra(stack_A);
    }

}