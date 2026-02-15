/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:23:48 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:04:46 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rrb(t_stack *stack)
{
	t_node	*last_node;

	if (!stack || !stack->top)
		return ;
	last_node = ft_stack_pop_back(stack);
	ft_stack_push(stack, last_node);
	ft_printf("rrb\n");
}
