/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_circle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:39:57 by adrian            #+#    #+#             */
/*   Updated: 2026/08/03 18:42:55 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_print_circle(t_coder	*first_coder)
{
	t_coder	*current_coder;

	current_coder = first_coder;
	while (current_coder != first_coder->previous)
	{
		printf("Current Coder is %d, ", current_coder->number);
		printf("Next Coder: %d, ", current_coder->next->number);
		printf("Previous One: %d\n", current_coder->previous->number);
		current_coder = current_coder->next;
	}
	printf("Current Coder is %d, ", current_coder->number);
	printf("Next Coder: %d, ", current_coder->next->number);
	printf("Previous One: %d\n", current_coder->previous->number);
	printf("\n");
}
