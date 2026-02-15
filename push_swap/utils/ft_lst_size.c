/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:26:13 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 13:09:28 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_lst_size(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
