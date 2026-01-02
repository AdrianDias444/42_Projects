#include "../header.h"

// ft_pb, we need to place the first element of stack A in the first position in stack B, for this we need to save the 2 position in stack A, put the pointer of first node in  stack A pointing the first element to stack B, and now we recover the save second element on stack A and this is now the first element of stack A. The same logical but inverse letters for ft_pa


t_node *ft_pb(t_node *first_node_A, t_node *first_node_B)
{
    if(!first_node_A)
        return(NULL);
    if(!first_node_B)
    {
        first_node_A -> next = NULL;
        return(first_node_A);
    }
    first_node_A -> next = first_node_B;

    return(first_node_A);
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