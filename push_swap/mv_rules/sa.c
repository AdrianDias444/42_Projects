#include "../header.h"

void sa(t_stack *stack)
{
    t_node *first_node;
    t_node *second_node;
    t_node *third_node;

    if(!stack || !stack->top || !stack->top->next)
        return ;
    first_node = stack -> top;
    second_node = first_node -> next;
    third_node = second_node -> next;

    stack ->top = second_node;
    second_node -> next = first_node;
    first_node -> next = third_node;
}

// int main(void)
// {
//     t_stack stack_B;
//     t_node *first_node;

//     ft_stack_init(&stack_B);

//     first_node = ft_create_node(7);
//     ft_stack_push_back(&stack_B, first_node);

//     sa(&stack_B);
// }