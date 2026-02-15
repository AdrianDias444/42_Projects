/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:18 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 11:24:19 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_node	*ft_stack_pop_back(t_stack *stack)
{
	t_node	*node_to_remove;
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	node_to_remove = ft_last_node(stack);
	if (current == node_to_remove && current->next == NULL)
	{
		stack->top = NULL;
		return (node_to_remove);
	}
	while (current->next && current->next != node_to_remove)
		current = current->next;
	current->next = NULL;
	return (node_to_remove);
}

/* int main(void)
{
	t_node *first_node;
	t_node *second_node;
	t_node *third_node;

	t_stack stack;

	ft_stack_init(&stack);

	first_node = ft_create_node(1);
	ft_stack_push_back(&stack, first_node);

	second_node = ft_create_node(40);
	ft_stack_push_back(&stack, second_node);

	third_node = ft_create_node(8);
	ft_stack_push_back(&stack, third_node);

	ft_print_stack(&stack);

	t_node *node_to_remove = ft_stack_pop_back(&stack);

	printf("\n");

	ft_print_stack(&stack);

	printf("Node deleted %d", node_to_remove -> nb);
} */