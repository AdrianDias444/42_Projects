/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:44:59 by adrian            #+#    #+#             */
/*   Updated: 2026/08/03 18:59:21 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_coder	*ft_edf(t_dongle *dongle)
{
	t_heap	*heap;
	t_coder	*first_coder;
	t_coder	*second_coder;
	long	time1;
	long	time2;

	heap = dongle->dongle_heap;
	first_coder = heap->first;
	second_coder = first_coder->heap_next;
	if (!second_coder)
		return (first_coder);
	time1 = first_coder -> time_of_last_compile;
	time2 = second_coder -> time_of_last_compile;
	if (time1 < time2)
		return (first_coder);
	return (second_coder);
}
