#include "../header.h"


void ft_insert_node(t_stack *stack_A, t_stack *stack_B)
{
    int find_place = ft_find_place(stack_B, stack_A->top);

    int count;

    count = 0;
    while(ft_min_bellow(stack_A, stack_A->top) != stack_A->top)
    {
        if(find_place == 1)
        {
            rb(stack_B);
            count++;
        }
        else
        {
            rrb(stack_B);
            count++;
        }
    }
    pb(stack_A, stack_B);
}



//while(ft_min_node(stack_B)->nb < stack_A->top->nb && stack_A->top->nb < ft_max_node(stack_B)->nb && !(stack_B->top->nb < stack_A->top->nb && stack_A->top->nb < ft_last_node(stack_B)->nb))
