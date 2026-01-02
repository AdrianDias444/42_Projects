#include "../header.h"

t_node **ft_ss(t_node *first_nodeA, t_node *first_nodeB)
{
    ft_sa(first_nodeA);
    ft_sb(first_nodeB);

    return(first_nodeA, first_nodeB)
}

// int main(int argc, char **argv)
// {
//     int i;
//     int nb;
//     t_node *new_node_A = NULL;
//     t_node *current_A = NULL;
//     t_node *first_node_A = NULL;
//     t_node *first_node_B;

//     first_node_B = malloc(sizeof(t_node));
//     /* first_node_B->nb = NULL;
//     first_node_B->next = NULL; */

//     i = 1;
//     if(argc > 1)
//     {
//         while(i < argc)
//         {
//             nb = ft_atoi(argv[i]);
//             new_node_A = ft_to_stackA(nb, i, current_A);
//             current_A = new_node_A;
//             i++;
//             if(!first_node_A)
//                 first_node_A = current_A;
//         }
//         printf("BEFORE\n");
//         printf("Stack A\n");
//         ft_print_node(first_node_A);

//         printf("Stack B\n");
//         ft_print_node(first_node_B);

//         current_A = first_node_A -> next;
//         first_node_B = ft_pb(first_node_A, first_node_B);
        
//         printf("\nPB MOVE TEST\n\n");
//         printf("Stack A\n");
//         ft_print_node(current_A);
//         printf("Stack B\n");
//         ft_print_node(first_node_B);
        
//     }
// }