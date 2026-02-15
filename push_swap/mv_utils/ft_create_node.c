/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addias <addias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:24:07 by addias            #+#    #+#             */
/*   Updated: 2026/02/15 11:24:11 by addias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_node	*ft_create_node(long long value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nb = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

// int main(void)
// {
//     t_node *new_node;

//     new_node = ft_create_node(12);
//     printf("Node value is %d\n", new_node -> nb);
//     printf("Node index is %d\n", new_node -> index);
//     printf("Node next is %p", new_node -> next);
// }