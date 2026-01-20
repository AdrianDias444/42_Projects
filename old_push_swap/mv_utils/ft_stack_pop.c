#include "../header.h"

t_node *ft_stack_pop(t_stack *stack)
{
    t_node *node_to_remove;

    if(!stack || !stack -> top)
        return (NULL);

    node_to_remove = stack -> top;
    stack -> top = stack -> top -> next;

    node_to_remove -> next = NULL;
    stack->size--;

    return(node_to_remove);
}


/* int main(void)
{
    t_stack stack_A;
    t_node *first_node;
    t_node *second_node;
    t_node *third_node;

    ft_stack_init(&stack_A);

    first_node = ft_create_node(98);
    ft_stack_push(&stack_A, first_node);

    second_node = ft_create_node(45);
    ft_stack_push(&stack_A, second_node);

    third_node = ft_create_node(31);
    ft_stack_push(&stack_A, third_node);

    ft_print_stack(&stack_A);


    ft_stack_pop(&stack_A);
    
    printf("\n");
    ft_print_stack(&stack_A);

} */