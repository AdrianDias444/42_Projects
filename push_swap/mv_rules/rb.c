/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:23:38 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:04:05 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rb(t_stack *stack)
{
	t_node	*first_node;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first_node = ft_stack_pop(stack);
	ft_stack_push_back(stack, first_node);
	ft_printf("rb\n");
}
