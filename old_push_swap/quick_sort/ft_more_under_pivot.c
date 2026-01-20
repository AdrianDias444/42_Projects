#include "../header.h"

int ft_more_under_pivot(t_stack *stack, t_node *pivot)
{
    t_node *current;
    int i;
    int count_1st_mid;
    int count_2nd_mid;
    int mid;

    mid = ft_lst_size(stack)/2;

    if(ft_lst_size(stack) % 2 != 0)
        mid++;
    current = stack->top;
    i = 0;
    count_1st_mid = 0;
    count_2nd_mid = 0;
    while(current)
    {
        while(i < mid)
        {
            if(current->nb <= pivot->nb)
                count_1st_mid++;
            i++;
            current = current->next;
        }
        if(current->nb <= pivot->nb)
            count_2nd_mid++;
        current = current->next;
        if(count_1st_mid < count_2nd_mid)
            return(-1);
    }
    return(1);
}