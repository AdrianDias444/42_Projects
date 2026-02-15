/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:23:31 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 12:03:54 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	pb(t_stack *stack_A, t_stack *stack_B)
{
	t_node	*node_to_push;

	if (!stack_A || !stack_A->top)
		return ;
	node_to_push = ft_stack_pop(stack_A);
	ft_stack_push(stack_B, node_to_push);
	ft_printf("pb\n");
}

// int main(void)
// {
//     t_node *first_node;
//     t_node *second_node;

//     t_stack stack_A;
//     t_stack stack_B;

//     ft_stack_init(&stack_A);
//     ft_stack_init(&stack_B);

//     first_node = ft_create_node(5);
//     ft_stack_push_back(&stack_A, first_node);

//     second_node = ft_create_node(2);
//     ft_stack_push_back(&stack_A, second_node);

//     printf("stack A\n");
//     ft_print_stack(&stack_A);
//     printf("\nstack B\n");
//     ft_print_stack(&stack_B);

//     printf("\n-----------\n");
//     pb(&stack_A, &stack_B);

//     printf("Stack A\n");
//     ft_print_stack(&stack_A);
//     printf("\nStack B \n");
//     ft_print_stack(&stack_B);
// }
