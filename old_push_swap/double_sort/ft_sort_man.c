#include "../header.h"

void ft_sort_man(t_stack *stack_A, t_stack *stack_B)
{
    int stack_A_size = ft_lst_size(stack_A);

    if(stack_A_size == 2)
        if(stack_A->top->nb > stack_A->top->next->nb)
            sa(stack_A);
    if(stack_A_size == 3)
        ft_sort_3_elem(stack_A);
    if(stack_A_size == 4)
    {
        pb(stack_A, stack_B);
        ft_sort_3_elem(stack_A);
        if(stack_B->top->nb > ft_max_node(stack_A)->nb)
        {
            pa(stack_B, stack_A);
            ra(stack_A);
            return ;
        }
        if(stack_B->top->nb < ft_min_node(stack_A)->nb)
        {
            pa(stack_B, stack_A);
            return;
        }
        if(stack_A->top->nb < stack_B->top->nb)
            ra(stack_A);
        if(stack_A->top->nb < stack_B->top->nb)
            ra(stack_A);
        pa(stack_B, stack_A);
        while(stack_A->top!=ft_min_node(stack_A))
            rra(stack_A);
    }

}