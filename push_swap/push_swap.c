#include "header.h"

//stack len -> sort(stackA, stackA->next)

t_node *sort(t_node *stackA, int stack_len)
{
    t_node *current_A;
    t_node *current_B;
    t_node *tmp_A;
    t_node *tmp_B;
    int i;
    
    current_A = malloc(sizeof(t_node));
    current_A = stackA;
    current_B = malloc(sizeof(t_node));
    current_B = NULL;
    tmp_A = malloc(sizeof(t_node));
    tmp_B = malloc(sizeof(t_node));
    i = stack_len;
    while(i > 3)
    {
        printf("nb is %d", i);
        current_B = ft_pb(current_A, current_B);
        current_A = current_A -> next;
        i--;
    }
    return(current_A);
}

int main(int argc, char **argv)
{
    int i;
    int nb;
    t_node *new_node_A = NULL;
    t_node *current_A = NULL;
    t_node *first_node_A = NULL;
    //ft_node *first_node_B = NULL;

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
    ft_print_node(first_node_A);
    printf("\n");
    current_A = sort(first_node_A, i);
    ft_print_node(current_A);
}