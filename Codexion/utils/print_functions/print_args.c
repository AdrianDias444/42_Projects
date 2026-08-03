/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:39:38 by adrian            #+#    #+#             */
/*   Updated: 2026/08/03 18:39:39 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_print_args(t_args args)
{
	printf("Number of coders: %d\n", args.number_of_coders);
	printf("Time to burnout: %d\n", args.time_to_burnout);
	printf("Time to compile: %d\n", args.time_to_compile);
	printf("Time to debug: %d\n", args.time_to_debug);
	printf("Time to refactor: %d\n", args.time_to_refactor);
	printf("Number of compiles: %d\n", args.number_of_compiles_required);
	printf("Dongle Cooldown: %d\n", args.dongle_cooldown);
	printf("Scheduler: %s\n", args.scheduler);
	printf("\n");
}
