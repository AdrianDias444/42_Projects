/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:25:31 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 11:25:42 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_calc_cost(t_stack *stack, t_node *node_to_calc)
{
	t_node	*current;
	int		i;

	if (!stack || !stack->top || !node_to_calc)
		return (0);
	current = stack->top;
	i = 0;
	while (current && current != node_to_calc)
	{
		i++;
		current = current->next;
	}
	if (ft_is_in_middle(stack, node_to_calc))
		return (1);
	if (i < ft_lst_size(stack) / 2)
		return (1);
	return (-1);
}

/* int main(void)
{
	t_node *first_node;
	t_node *second_node;
	t_node *third_node;
	t_node *fourth_node;
	t_node  *fifth_node;
	t_stack stack;
	ft_stack_init(&stack);
	first_node = ft_create_node(6);
	ft_stack_push_back(&stack, first_node);
	second_node = ft_create_node(3);
	ft_stack_push_back(&stack, second_node);
	third_node = ft_create_node(5);
	ft_stack_push_back(&stack, third_node);
	fourth_node = ft_create_node(2);
	ft_stack_push_back(&stack, fourth_node);

	int i = ft_calc_cost(&stack, fifth_node);
	printf("Cost is %d\n", i);
} */