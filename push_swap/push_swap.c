#include "header.h"

int main(int argc, char **argv)
{
    int i;
    int nb;
    t_node *new_node_A = NULL;
    t_node *current_A = NULL;
    t_node *first_node_A = NULL;
    //t_node *first_node_B = NULL;

    i = 1;
    if(argc > 1)
    {
        while(i < argc)
        {
            nb = ft_atoi(argv[i]);
            new_node_A = ft_to_stackA(nb, i, current_A);
            current_A = new_node_A;
            i++;
            if(!first_node_A)
                first_node_A = current_A;
        }
    }
}