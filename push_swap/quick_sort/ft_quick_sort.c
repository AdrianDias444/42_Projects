#include "../header.h"

void ft_quick_sort(t_stack *stack_A, t_stack *stack_B)
{

    if(ft_is_ordered(stack_A) == 1)
        return ;

    ft_make_a_cicle(stack_A, stack_B);
    ft_print_stack(stack_B);
/*     while(ft_lst_size(stack_A) > 3)
        ft_remake_cicle(stack_A, stack_B);

    if(ft_lst_size(stack_A) == 3)
        ft_sort_3_elem(stack_A);
    else
        if(ft_is_ordered(stack_A) == 0)
            sa(stack_A);

    while(stack_B->top)
        pa(stack_B, stack_A); */

    /* if(ft_is_ordered(stack_A) == 1)
        printf("\nEsta ordenado\n"); */

}