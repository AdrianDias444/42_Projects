/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:26:44 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 11:58:49 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	ft_stack_init(&stack_a);
	ft_stack_init(&stack_b);
	if (argc > 1)
	{
		ft_parser(argc, argv, &stack_a);
		ft_quick_sort(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
}
