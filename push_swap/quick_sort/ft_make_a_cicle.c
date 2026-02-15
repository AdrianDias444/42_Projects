/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_a_cicle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:56 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:37:07 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_make_a_cicle(t_stack *stack_A, t_stack *stack_B)
{
	t_node	*pivot;

	if (ft_lst_size(stack_A) + ft_lst_size(stack_B) > 110)
		pivot = ft_return_mid_mid(stack_A);
	else
		pivot = ft_return_mid(stack_A);
	while (ft_min_node(stack_A)->nb <= pivot->nb)
	{
		if (stack_A->top->nb <= pivot->nb)
		{
			if (!stack_B->top)
				pb(stack_A, stack_B);
			else if (!stack_B->top->next)
			{
				pb(stack_A, stack_B);
				if (stack_B->top->nb < stack_B->top->next->nb)
					sb(stack_B);
			}
			else
				ft_insert_node(stack_A, stack_B);
		}
		else
			ra(stack_A);
	}
	free(pivot);
}
