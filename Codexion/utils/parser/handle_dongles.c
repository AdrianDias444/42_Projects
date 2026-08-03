/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dongles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:36:18 by adrian            #+#    #+#             */
/*   Updated: 2026/08/03 18:36:45 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_add_dongle_right(t_coder	*coder, t_dongle	*dongle)
{
	coder -> right_dongle = dongle;
}

void	ft_add_dongle_left(t_coder	*coder, t_dongle	*dongle)
{
	coder -> left_dongle = dongle;
}

void	ft_add_next_dongle(t_dongle	*current_dongle, t_dongle	*next_dongle)
{
	current_dongle->next = next_dongle;
}

void	*ft_handle_dongles(t_circle	*circle)
{
	t_coder		*current_coder;
	t_dongle	*current_dongle;
	t_dongle	*first_dongle;
	t_heap		*heap;
	char		c;

	c = 'A';
	current_coder = circle->first_coder;
	first_dongle = ft_create_dongle();
	heap = ft_create_heap();
	first_dongle -> dongle_heap = heap;
	if (!first_dongle)
		return (NULL);
	first_dongle->dongle_cooldown = circle -> dongle_cooldown;
	current_dongle = first_dongle;
	while (current_coder != circle->first_coder->previous)
	{
		if (current_dongle != first_dongle)
			ft_add_next_dongle(first_dongle, current_dongle);
		current_dongle->name = c;
		ft_add_dongle_right(current_coder, current_dongle);
		current_coder = current_coder -> next;
		ft_add_dongle_left(current_coder, current_dongle);
		first_dongle = current_dongle;
		current_dongle = ft_create_dongle();
		heap = ft_create_heap();
		current_dongle -> dongle_cooldown = circle -> dongle_cooldown;
		current_dongle -> dongle_heap = heap;
		c++;
	}
	current_dongle->name = c;
	ft_add_dongle_right(current_coder, current_dongle);
	ft_add_dongle_left(circle->first_coder, current_dongle);
	ft_add_next_dongle(first_dongle, current_dongle);
	return (NULL);
}
