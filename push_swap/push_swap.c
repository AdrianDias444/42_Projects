#include "header.h"

int main(int argc, char **argv)
{
    t_stack stack_A;
    t_stack stack_B;

    ft_stack_init(&stack_A);
    ft_stack_init(&stack_B);
    //////////////////////////////////////////////////
    if(argc > 1)
    {
        ft_parser(argc, argv, &stack_A);
        ft_quick_sort(&stack_A, &stack_B);
    }
    //ft_print_stack(&stack_A);
    ft_free_stack(&stack_A);
    //ft_free_stack(&stack_B);

}