#include "../header.h"

t_node *ft_return_mid_mid(t_stack *stack)
{

    int node_to_remove;
    int node_count;
    t_node *max_node;
    t_stack stack_dup;
    t_node *pivot_mid_mid;
    t_node *to_del;

    ft_stack_init(&stack_dup);
    node_to_remove = ft_lst_size(stack)/2 + ft_lst_size(stack)/4 + ft_lst_size(stack)/8;
    node_count = 0;
    stack_dup = ft_dup_stack(stack);

    max_node = ft_max_node(&stack_dup);;
    while(node_to_remove > node_count)
    {
        max_node = ft_max_node(&stack_dup);
        to_del = ft_remove_this_node(&stack_dup, max_node);
        free(to_del);
        node_count++;
    }
    pivot_mid_mid = ft_remove_this_node(&stack_dup, ft_max_node(&stack_dup));
    ft_free_stack(&stack_dup);
    return(pivot_mid_mid);
}