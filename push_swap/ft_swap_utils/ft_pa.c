#include "../header.h"

t_node *ft_pa(t_node *first_node_B, t_node *first_node_A)
{
    if(!first_node_B)
        return(NULL);
    if(!first_node_A)
    {
        first_node_B -> next = NULL;
        return(first_node_B);
    }
    first_node_B->next = first_node_A;
    return(first_node_B);
}


int main(int argc, char **argv)
{
    int i;
    int nb;
    t_node *new_node_A = NULL;
    t_node *current_A = NULL;
    t_node *first_node_A = NULL;
    t_node *first_node_B;

    first_node_B = malloc(sizeof(t_node));
    first_node_B->nb = 67;
    first_node_B->next = NULL;

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
        printf("BEFORE\n");
        ft_print_node(first_node_A);
        first_node_A = ft_pa(first_node_B, first_node_A);
        printf("PA MOVE TEST\n");
        ft_print_node(first_node_A);
        
    }
}