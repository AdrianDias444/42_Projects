#include "../header.h"

void sb(t_stack *stack)
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