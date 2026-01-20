#include "../header.h"

void ft_stack_push_back(t_stack *stack, t_node *node)
{
    t_node *last;

    if(!stack->top)
    {
        stack -> top = node;
        return ;
    }
    last = ft_last_node(stack);
    last -> next = node;
}

// int main(void)
// {
//     t_node *first_node;
//     t_node *second_node;
//     t_node *third_node;
//     t_node *fourth_node;

//     t_stack stack_A;

//     ft_stack_init(&stack_A);

//     first_node = ft_create_node(1);
//     ft_stack_push_back(&stack_A, first_node);

//     second_node = ft_create_node(6);
//     ft_stack_push_back(&stack_A, second_node);

//     third_node = ft_create_node(8);
//     ft_stack_push_back(&stack_A, third_node);

//     fourth_node = ft_create_node(0);
//     ft_stack_push_back(&stack_A, fourth_node);

//     ft_print_stack(&stack_A);
// }