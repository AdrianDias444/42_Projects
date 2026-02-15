/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:23:54 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:04:26 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sa(t_stack *stack)
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
	ft_printf("sa\n");
}

// int main(void)
// {
//     t_stack stack_B;
//     t_node *first_node;

//     ft_stack_init(&stack_B);

//     first_node = ft_create_node(7);
//     ft_stack_push_back(&stack_B, first_node);

//     sa(&stack_B);
// }