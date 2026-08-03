/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:30:37 by adrian            #+#    #+#             */
/*   Updated: 2026/08/03 18:32:51 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_add_times(t_args args, t_coder	*coder)
{
	coder->time_to_compile = args.time_to_compile;
	coder->time_to_debug = args.time_to_debug;
	coder->time_to_refactor = args.time_to_refactor;
	coder->time_to_burnout = args.time_to_burnout;
	coder->start_ms = args.start_ms;
	coder -> time_of_last_compile = args.start_ms;
}

t_circle	*ft_handle_circle(t_args args)
{
	int			i;
	t_coder		*first_coder;
	t_coder		*current_coder;
	t_coder		*next_coder;
	t_circle	*circle;

	first_coder = ft_create_coder(1);
	ft_add_times(args, first_coder);
	current_coder = first_coder;
	i = 2;
	while (i <= args.number_of_coders)
	{
		next_coder = ft_create_coder(i);
		ft_add_times(args, next_coder);
		ft_add_next_coder(current_coder, next_coder);
		ft_add_previous_coder(next_coder, current_coder);
		current_coder = next_coder;
		i++;
	}
	current_coder -> next = first_coder;
	first_coder -> previous = current_coder;
	circle = ft_create_circle(first_coder, args);
	circle->dongle_cooldown = args.dongle_cooldown;
	return (circle);
}
