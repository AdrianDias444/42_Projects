/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:23:58 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:27:05 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sb(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first_node = stack->top;
	second_node = first_node->next;
	third_node = second_node->next;
	stack->top = second_node;
	second_node->next = first_node;
	first_node->next = third_node;
	ft_printf("sb\n");
}
