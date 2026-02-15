/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_below.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:59 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:45:19 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_node	*ft_min_bellow(t_stack *stack_B, t_node *node_to_calc)
{
	t_stack	new_stack;
	t_node	*min;
	t_node	*to_del;

	if (!stack_B->top || !stack_B->top->next)
		return (NULL);
	if (node_to_calc->nb == ft_min_node(stack_B)->nb)
		return (NULL);
	new_stack = ft_dup_stack(stack_B);
	while (ft_max_node(&new_stack)->nb >= node_to_calc->nb)
	{
		to_del = ft_remove_this_node(&new_stack, ft_max_node(&new_stack));
		free(to_del);
	}
	min = ft_remove_this_node(&new_stack, ft_max_node(&new_stack));
	ft_free_stack(&new_stack);
	return (min);
}
