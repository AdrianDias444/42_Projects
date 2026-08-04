/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:35:53 by adrian            #+#    #+#             */
/*   Updated: 2026/08/04 13:46:03 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_args	*ft_create_args(void)
{
	t_args*	args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->number_of_coders = NUMBER_OF_CODERS;
	args->time_to_burnout = TIME_TO_BURNOUT;
	args->time_to_compile = TIME_TO_COMPILE;
	args->time_to_debug = TIME_TO_DEBUG;
	args->time_to_refactor = TIME_TO_REFACTOR;
	args->nb_of_comp_req = NUMBER_OF_COMPILES_REQUIRED;
	args->dongle_cooldown = DONGLE_COOLDOWN;
	args->scheduler = handle_string(SCHEDULER);
    args->start_ms = ft_return_time_now();

	return (args);
}