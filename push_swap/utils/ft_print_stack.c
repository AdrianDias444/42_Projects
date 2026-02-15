/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:26:22 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 13:09:07 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		ft_printf("Stack vazia ou nao inicilizada\n");
		return ;
	}
	current = stack->top;
	while (current)
	{
		ft_printf("%d\n", current->nb);
		current = current->next;
	}
}
