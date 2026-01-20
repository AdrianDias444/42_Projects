#include "../header.h"

void ft_quick_sort(t_stack *stack_A, t_stack *stack_B)
{

    if(ft_is_ordered(stack_A) == 1)
        return ;
    // alterar a logica deste if
    while(ft_lst_size(stack_A) - ft_how_many_not_order(stack_A) > 3)
    {
        //printf("\ndiferenca e %d\n", ft_lst_size(stack_A) - ft_how_many_not_order(stack_A));
        ft_make_a_cicle(stack_A, stack_B);
        //printf("\ndiferenca e %d\n", ft_lst_size(stack_A) - ft_how_many_not_order(stack_A));
    }

    if(ft_lst_size(stack_A) - ft_how_many_not_order(stack_A) == 2)
    {
        if(stack_A->top->nb > stack_A->top->next->nb)
            sa(stack_A);
    }
    else if(ft_lst_size(stack_A) - ft_how_many_not_order(stack_A) == 3)
        ft_sort_3_elem(stack_A, stack_B);
}