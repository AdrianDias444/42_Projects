/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:44 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:28:22 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_stack	ft_dup_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*current_to_add;
	t_stack	new_stack;

	ft_stack_init(&new_stack);
	current = stack->top;
	while (current)
	{
		current_to_add = ft_create_node(current->nb);
		ft_stack_push_back(&new_stack, current_to_add);
		current = current->next;
	}
	return (new_stack);
}
