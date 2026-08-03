/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dongles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:43:16 by adrian            #+#    #+#             */
/*   Updated: 2026/08/03 18:44:27 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_print_dongles(t_circle	*circle)
{
	t_coder		*current_coder;
	t_dongle	*current_dongle;

	current_coder = circle->first_coder;
	current_dongle = circle->first_coder->right_dongle;
	while (current_dongle != circle->first_coder->left_dongle)
	{
		printf("Current Coder is : %d | ", current_coder->number);
		printf("Left Dongle is: %c | ", current_coder->left_dongle->name);
		printf("Right Dongle is: %c \n", current_coder->right_dongle->name);
		current_coder = current_coder->next;
		current_dongle = current_dongle -> next;
	}
	printf("Current Coder is : %d | ", current_coder->number);
	printf("Left Dongle is: %c | ", current_coder->left_dongle->name);
	printf("Right Dongle is: %c \n", current_coder->right_dongle->name);
}
