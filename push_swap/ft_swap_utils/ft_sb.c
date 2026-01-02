#include "../header.h"

t_node *ft_sa(t_node *first_node_B)
{
    t_node *second_node_B;
    t_node *third_node_B;

    if(!first_node_B)
        return (NULL);
    second_node_B = first_node_B -> next;
    if(!second_node_B)
        return(first_node_B);
    third_node_B = second_node_B -> next;

    first_node_B -> next = third_node_B;
    second_node_B ->next = first_node_B;


    return(second_node_B);
}