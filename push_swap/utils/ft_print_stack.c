#include "../header.h"

void ft_print_stack(t_stack *stack)
{
    t_node *current;

    if(!stack || !stack -> top)
    {
        printf("Stack vazia ou nao inicilizada");
        return ;
    }
    current = stack -> top;
    while(current)
    {
        printf("%d\n", current -> nb);
        current = current -> next;
    }
}