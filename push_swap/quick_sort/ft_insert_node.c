/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:50 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:48:11 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_insert_node(t_stack *stack_A, t_stack *stack_B)
{
	int		find_place;
	t_node	*min;

	find_place = ft_find_place(stack_B, stack_A->top);
	if (stack_A->top->nb > ft_min_node(stack_B)->nb)
	{
		min = ft_min_bellow(stack_B, stack_A->top);
		while (min->nb != stack_B->top->nb)
		{
			if (find_place == 1)
				rb(stack_B);
			else
				rrb(stack_B);
		}
		free(min);
	}
	else
		while (stack_B->top->nb != ft_max_node(stack_B)->nb)
			rb(stack_B);
	pb(stack_A, stack_B);
}
