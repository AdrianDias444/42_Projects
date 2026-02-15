/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_middle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:26:02 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 13:08:21 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_is_in_middle(t_stack *stack, t_node *node)
{
	int		i;
	int		j;
	t_node	*current;

	if (!stack || !stack->top || !node)
		return (-1);
	i = 0;
	j = 0;
	current = stack->top;
	while (current && current != node)
	{
		i++;
		current = current->next;
	}
	while (current && current->next)
	{
		j++;
		current = current->next;
	}
	if (j == i)
		return (1);
	return (0);
}

/* int main(void)
{
	t_node *first_node;
	t_node *second_node;
	t_node *third_node;
	t_node *fourth_node;
	t_node *fifth_node;

	t_stack stack;

	ft_stack_init(&stack);

	first_node = ft_create_node(5);
	ft_stack_push_back(&stack, first_node);

	second_node = ft_create_node(7);
	ft_stack_push_back(&stack, second_node);

	third_node = ft_create_node(4);
	ft_stack_push_back(&stack, third_node);

	fourth_node = ft_create_node(1);
	ft_stack_push_back(&stack, fourth_node);

	fifth_node = ft_create_node(3);
	ft_stack_push_back(&stack, fifth_node);

	int i = ft_is_in_middle(&stack, third_node);
	printf("%d", i);
} */