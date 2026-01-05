#include "../header.h"

void ft_quick_sort(t_stack *stack_A, t_stack *stack_B)
{
     int lst_size;
    int nodes_to_push;

    if(ft_is_ordered(stack_A) == 1)
        return ;

    lst_size = ft_lst_size(stack_A);
    nodes_to_push = lst_size/2;

    if(lst_size%2 != 0)
        nodes_to_push++;
    while(ft_lst_size(stack_A) > nodes_to_push)
        pb(stack_A, stack_B);
/*     while(lst_size(stack_B) > 2)
    {

    } */
}