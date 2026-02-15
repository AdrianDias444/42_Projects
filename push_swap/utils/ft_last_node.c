/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:26:10 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 13:08:34 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_node	*ft_last_node(t_stack *stack)
{
	t_node	*current;

	if (!stack->top)
		return (NULL);
	current = stack->top;
	while (current->next)
		current = current->next;
	return (current);
}

// int main(void)
// {
//     t_node *first_node;
//     t_node *last_node;

//     t_stack stack;

//     ft_stack_init(&stack);

//     first_node = ft_create_node(2);
//     ft_stack_push_back(&stack, first_node);

//     last_node = ft_last_node(&stack);

//     ft_print_stack(&stack);
//     printf("\n%d", last_node -> nb);
// }