/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:25:47 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 13:08:16 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*current_prev;

	if (!stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		current_prev = current;
		current = current->next;
		free(current_prev);
	}
}
