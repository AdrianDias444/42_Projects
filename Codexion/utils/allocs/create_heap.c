/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:29:21 by adrian            #+#    #+#             */
/*   Updated: 2026/08/03 18:30:02 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_heap	*ft_create_heap(void)
{
	t_heap	*heap;

	heap = malloc(sizeof(t_heap));
	if (!heap)
		return (NULL);
	heap -> first = NULL;
	heap -> how_many_waiting = 0;
	pthread_mutex_init(&heap->mutex, NULL);
	return (heap);
}
