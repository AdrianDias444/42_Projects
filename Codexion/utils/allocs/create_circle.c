/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:22:26 by adrian            #+#    #+#             */
/*   Updated: 2026/08/04 13:46:33 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_circle	*ft_create_circle(t_coder *coder, t_args *args)
{
	t_circle	*circle;

	circle = malloc(sizeof(t_circle));
	if (!circle)
		return (NULL);
	circle -> first_coder = coder;
	circle -> number_of_coders = args->number_of_coders;
	circle -> nb_dongles = args->number_of_coders;
	circle -> nb_of_comp_req = args->nb_of_comp_req;
	circle -> args_struct = args;
	return (circle);
}
