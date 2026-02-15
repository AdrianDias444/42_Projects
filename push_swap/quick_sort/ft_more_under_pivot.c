/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_under_pivot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:25:02 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 13:07:43 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_verify(int i, int mid, t_node *current, t_node *pivot)
{
	int		count_1st_mid;
	int		count_2nd_mid;

	count_1st_mid = 0;
	count_2nd_mid = 0;
	while (current)
	{
		while (i < mid)
		{
			if (current->nb <= pivot->nb)
				count_1st_mid++;
			i++;
			current = current->next;
		}
		if (current->nb <= pivot->nb)
			count_2nd_mid++;
		current = current->next;
		if (count_1st_mid < count_2nd_mid)
			return (-1);
	}
	return (1);
}

int	ft_more_under_pivot(t_stack *stack, t_node *pivot)
{
	t_node	*current;
	int		i;
	int		mid;

	mid = ft_lst_size(stack) / 2;
	if (ft_lst_size(stack) % 2 != 0)
		mid++;
	current = stack->top;
	i = 0;
	ft_verify(i, mid, current, pivot);
	return (1);
}
