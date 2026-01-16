#include "header.h"

int main(int argc, char **argv)
{
    int i;
    //int j;
    int nb;
    t_stack stack_A;
    t_stack stack_B;
    t_node *current;


    i = 1;
    ft_stack_init(&stack_A);
    ft_stack_init(&stack_B);
    /////////////////////////////////////////////////
    /* if(argc == 2)
    {
        char **str = ft_split(argv[1], 32);
        j = 0;

        while(str[j])
        {
            nb = ft_atoi(str[j]);
            current = ft_create_node(nb);
            ft_stack_push_back(&stack_A, current);
            j++;
        }
        ft_quick_sort(&stack_A, &stack_B);
        return 0;
    } */
    //////////////////////////////////////////////////
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
        ft_quick_sort(&stack_A, &stack_B);
        //ft_double_sort(&stack_A, &stack_B);
        ft_print_stack(&stack_B);


    }
}