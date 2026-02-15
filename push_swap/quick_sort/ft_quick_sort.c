/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:25:06 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:49:26 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_rotate_stack_b(t_stack *stack_B)
{
	while (stack_B->top != ft_max_node(stack_B))
	{
		if (ft_calc_cost(stack_B, ft_max_node(stack_B)) == 1)
			rb(stack_B);
		else
			rrb(stack_B);
	}
}

void	ft_quick_sort(t_stack *stack_A, t_stack *stack_B)
{
	if (ft_is_ordered(stack_A) == 1)
		return ;
	while (ft_lst_size(stack_A) > 3)
	{
		ft_make_a_cicle(stack_A, stack_B);
		ft_rotate_stack_b(stack_B);
	}
	if (ft_lst_size(stack_A) == 2)
		if (stack_A->top->nb > stack_A->top->next->nb)
			sa(stack_A);
	if (ft_lst_size(stack_A) == 3)
		ft_sort_3_elem(stack_A);
	while (stack_B->top)
		pa(stack_B, stack_A);
}
