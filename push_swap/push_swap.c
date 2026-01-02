#include "header.h"

int main(int argc, char **argv)
{
    int i;
    int nb;
    t_stack stack_A;
    t_node *current;

    i = 1;
    ft_stack_init(&stack_A);
    if(argc > 1)
    {
        while(i < argc)
        {
            nb = ft_atoi(argv[i]);
            current = ft_create_node(nb);
            ft_stack_push(&stack_A, current);
            i++;
        }
    }
    ft_print_stack(&stack_A);
}