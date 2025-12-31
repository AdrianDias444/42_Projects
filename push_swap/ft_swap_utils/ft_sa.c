#include "../header.h"

t_node *ft_sa(t_node *first_node)
{
    t_node *second_node;
    t_node *third_node;

    if(!first_node)
        return (NULL);
    second_node = first_node -> next;
    third_node = second_node -> next;

    first_node -> next = third_node;
    second_node ->next = first_node;

    return(second_node);
}