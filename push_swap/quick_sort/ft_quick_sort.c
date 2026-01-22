#include "../header.h"

void ft_quick_sort(t_stack *stack_A, t_stack *stack_B)
{

    if(ft_is_ordered(stack_A) == 1)
        return ;

    while(ft_lst_size(stack_A) > 3)
        ft_make_a_cicle(stack_A, stack_B);
    
    if(ft_lst_size(stack_A) == 2)
        if(stack_A->top->nb > stack_A->top->next->nb)
            sa(stack_A);
    if(ft_lst_size(stack_A) == 3)
        ft_sort_3_elem(stack_A);
    while(stack_B->top)
        pa(stack_B, stack_A);

}