#include "../header.h"

void rra(t_stack *stack)
{
    t_node *last_node;

    if(!stack || !stack->top)
        return ;

    last_node = ft_stack_pop_back(stack);
    ft_stack_push(stack, last_node);
}



/* int main(void)
{
    t_node *first_node;
    t_node *second_node;
    t_node *third_node;
    t_node *fourth_node;

    t_stack stack;

    ft_stack_init(&stack);

    first_node = ft_create_node(5);
    ft_stack_push_back(&stack, first_node);

    second_node = ft_create_node(9);
    ft_stack_push_back(&stack, second_node);

    third_node = ft_create_node(3);
    ft_stack_push_back(&stack, third_node);

    fourth_node = ft_create_node(7);
    ft_stack_push_back(&stack, fourth_node);

    ft_print_stack(&stack);
    printf("\n");
    rra(&stack);

    ft_print_stack(&stack);
} */