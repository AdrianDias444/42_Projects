#include "header.h"

int main(int argc, char **argv)
{
    int i;
    int nb;
    t_node *new_node = NULL;
    t_node *current = NULL;
    t_node *first_node = NULL;

    i = 1;
    if(argc > 1)
    {
        while(i < argc)
        {
            nb = ft_atoi(argv[i]);
            new_node = ft_to_stackA(nb, i, current);
            current = new_node;
            i++;
            if(!first_node)
                first_node = current;
        }
        // ft_print_node(first_node);
        // first_node ft_sa(first_node);
        // printf("\n\n");
        // ft_print_node(first_node);
    }
}