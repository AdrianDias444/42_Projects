#include "../header.h"

void ft_parser(int argc, char **argv, t_stack *stack_A)
{
    int i;
    int j;
    long long nb;
    t_node *current;
    char **mat;

    i = 1;
    while(i < argc)
    {
        j = 0;
        if(ft_is_a_string(argv[i]) == 0)
        {
            mat = ft_split(argv[i], ' ');
            while(mat[j])
            {
                nb = ft_atoi(mat[j]);
                current = ft_create_node(nb);
                ft_stack_push_back(stack_A, current);
                j++;
            }
            j = 0;
            while(mat[j])
            {
                free(mat[j]);
                j++;
            }
        }
        else
        {
            nb = ft_atoi(argv[i]);
            current = ft_create_node(nb);
            ft_stack_push_back(stack_A, current);
        }
        i++;
    }
    //free(mat);
}