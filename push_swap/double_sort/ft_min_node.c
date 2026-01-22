#include "../header.h"

t_node *ft_min_node(t_stack *stack)
{
    t_node *min_node;
    t_node *current;

    if(!stack || !stack->top)
        return (NULL);
    current = stack->top;
    min_node = current;
    while(current)
    {
        if(min_node->nb > current->nb)
            min_node = current;
        current = current->next;
    }
    return(min_node);
}


/* int main(void)
{
    t_node *first_node;
    t_node *second_node;
    t_node *third_node;

    t_node *min_node;

    t_stack stack;

    ft_stack_init(&stack);

    first_node = ft_create_node(4);
    ft_stack_push_back(&stack, first_node);

    second_node = ft_create_node(2);
    ft_stack_push_back(&stack, second_node);

    third_node = ft_create_node(7);
    ft_stack_push_back(&stack, third_node);

    min_node = ft_min_node(&stack);

    printf("%d", min_node->nb)

} */