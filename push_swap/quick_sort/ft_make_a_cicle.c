#include "../header.h"

// make a cicle is wrong, for this new concept of quicksort, need to fix this function
void ft_make_a_cicle(t_stack *stack_A, t_stack *stack_B)
{
    t_node *pivot;
    //t_stack new_stack;

    //new_stack = ft_sub_stack(stack_A);
    pivot = ft_sub_pivot(stack_A);
    //printf("\nPivot number is %d\n", pivot->nb);

    //printf("pivot number is %d\n", pivot->nb);
    while(ft_return_max_sub_node(stack_A)->nb >= pivot->nb) 
    {
        if(stack_A->top->nb >= pivot->nb)
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
                ft_insert_node(stack_A, stack_B);
        }
        else
            ra(stack_A);

    }
    while(stack_B->top)
        pa(stack_B, stack_A);
    while(ft_last_node(stack_A) != ft_max_node(stack_A))
        rra(stack_A);
}