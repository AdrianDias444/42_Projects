#include "../header.h"

void ft_free_stack(t_stack *stack)
{
    t_node *current;
    t_node *current_prev;

    current = stack->top;
    while(current)
    {
        current_prev = current;
        current = current->next;
        free(current_prev);
    }
}