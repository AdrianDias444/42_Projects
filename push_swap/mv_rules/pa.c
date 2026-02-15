/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:23:24 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:03:49 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	pa(t_stack *stack_B, t_stack *stack_A)
{
	t_node	*node_to_push;

	if (!stack_B || !stack_B->top)
		return ;
	node_to_push = ft_stack_pop(stack_B);
	ft_stack_push(stack_A, node_to_push);
	ft_printf("pa\n");
}
