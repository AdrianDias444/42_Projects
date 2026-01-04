#include "header.h"

int main(int argc, char **argv)
{
    int i;
    int nb;
    t_stack stack_A;
    t_stack stack_B;
    t_node *current;

    i = 1;
    ft_stack_init(&stack_A);
    ft_stack_init(&stack_B);
    if(argc > 1)
    {
        while(i < argc)
        {
            nb = ft_atoi(argv[i]);
            current = ft_create_node(nb);
            ft_stack_push_back(&stack_A, current);
            i++;
        }
        ft_print_stack(&stack_A);
        if(i <= 5)
            ft_sort_man(&stack_A, &stack_B);
        else
            ft_double_sort(&stack_A, &stack_B);
        printf("\n");
        ft_print_stack(&stack_A);
    }
}