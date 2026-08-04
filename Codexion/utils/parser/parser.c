/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:38:17 by adrian            #+#    #+#             */
/*   Updated: 2026/08/04 13:37:44 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	handle_number(char	*str)
{
	int	nb;

	nb = atoi(str);
	if (nb == 0)
		return (-1);
	else
		return (nb);
}

char	*handle_string(char	*str)
{
	if (strcmp(str, "edf") != 0 && strcmp(str, "fifo") != 0)
		return (NULL);
	return (str);
}


/*
t_args*	ft_parser(void)
{
	t_args*	args;
	
	
	return (args);
}
*/
