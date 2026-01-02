#include "../header.h"

t_node *ft_sa(t_node *first_node_A)
{
    t_node *second_node_A;
    t_node *third_node_A;

    if(!first_node_A)
        return (NULL);
    second_node_A = first_node_A -> next;
    if(!second_node_A)
        return(first_node_A);
    third_node_A = second_node_A -> next;

    first_node_A -> next = third_node_A;
    second_node_A ->next = first_node_A;

    return(second_node_A);
}