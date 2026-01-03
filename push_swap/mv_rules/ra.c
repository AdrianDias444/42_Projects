#include "../header.h"

void ra(t_stack *stack)
{
    t_node *first_node;

    if(!stack || !stack->top || !stack->top->next)
        return ;
    first_node = ft_stack_pop(stack);
    ft_stack_push_back(stack, first_node);
}

int main(void)
{
    t_node *first_node;
    t_node *second_node;
    t_node *third_node;

    t_stack stack_A;
    t_stack stack_B;

    ft_stack_init(&stack_A);
    ft_stack_init(&stack_B);

    first_node = ft_create_node(5);
    ft_stack_push_back(&stack_A, first_node);

    second_node = ft_create_node(2);
    ft_stack_push_back(&stack_A, second_node);

    third_node = ft_create_node(9);
    ft_stack_push_back(&stack_A, third_node);

    ft_print_stack(&stack_A);
    printf("\n");
    ra(&stack_A);
    ft_print_stack(&stack_A);
}
