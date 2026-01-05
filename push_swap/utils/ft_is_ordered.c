#include "../header.h"

int ft_is_ordered(t_stack *stack)
{
    t_node *current;
    int i;

    i = 1;
    current = stack->top;
    while(current && current -> next)
    {
        if(current->nb > current ->next->nb)
            i = 0;
        current = current -> next;
    }
    return(i);
}

/* int main(void)
{
    t_node *first_node;
    t_node *second_node;
    t_node *third_node;

    t_stack stack;

    ft_stack_init(&stack);

    first_node = ft_create_node(1);
    ft_stack_push_back(&stack, first_node);

    second_node = ft_create_node(2);
    ft_stack_push_back(&stack, second_node);

    third_node = ft_create_node(3);
    ft_stack_push_back(&stack, third_node);
} */