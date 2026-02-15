/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:26:25 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 13:09:12 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_sort_3_elem(t_stack *stack_A)
{
	if (ft_max_node(stack_A) == stack_A->top)
		ra(stack_A);
	if (ft_max_node(stack_A) == stack_A->top->next)
		rra(stack_A);
	if (stack_A->top->nb > stack_A->top->next->nb)
		sa(stack_A);
}
