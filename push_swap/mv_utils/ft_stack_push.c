/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:28 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 11:24:28 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_stack_push(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	stack->top = node;
	stack->size = stack->size + 1;
}

/* int main(void)
{
	t_stack stack_A;

	t_node *first_node;
	t_node *second_node;
	t_node *third_node;

	ft_stack_init(&stack_A);

	first_node = ft_create_node(5);
	ft_stack_push(&stack_A, first_node);

	second_node = ft_create_node(12);
	ft_stack_push(&stack_A, second_node);

	third_node = ft_create_node(91);
	ft_stack_push(&stack_A, third_node);
	ft_print_stack(&stack_A);
} */