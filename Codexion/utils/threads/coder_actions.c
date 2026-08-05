/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:19:49 by adrian            #+#    #+#             */
/*   Updated: 2026/08/04 13:53:51 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_compile(t_coder	*coder)
{
	long	duration;

	pthread_mutex_lock(&coder->mutex_coder);
	coder->action = "compile";
	duration = ft_return_time_since_start(coder->start_ms);
	pthread_mutex_lock(&coder->simulation->mutex);
	printf("%ld %d is compilling\n", duration, coder->number);
	pthread_mutex_unlock(&coder->simulation->mutex);
	usleep(coder->time_to_compile * 1000);
	coder->last_compile = ft_return_time_now();
	coder->number_of_compiles_done += 1;
	coder->action = NULL;
	pthread_mutex_unlock(&coder->mutex_coder);
}

void	ft_debug(t_coder *coder)
{
	long	duration;

	pthread_mutex_lock(&coder->mutex_coder);
	duration = ft_return_time_since_start(coder->start_ms);
	coder->action = "debug";
	pthread_mutex_lock(&coder->simulation->mutex);
	printf("%ld %d is debugging\n", duration, coder->number);
	pthread_mutex_unlock(&coder->simulation->mutex);
	usleep(coder->time_to_debug * 1000);
	coder->action = NULL;
	pthread_mutex_unlock(&coder->mutex_coder);
}

void	ft_refactor(t_coder	*coder)
{
	long	duration;

	pthread_mutex_lock(&coder->mutex_coder);
	coder->action = "refactor";
	duration = ft_return_time_since_start(coder->start_ms);
	pthread_mutex_lock(&coder->simulation->mutex);
	printf("%ld %d is refactoring\n", duration, coder->number);
	pthread_mutex_unlock(&coder->simulation->mutex);
	usleep(coder->time_to_refactor * 1000);
	coder->action = NULL;
	pthread_mutex_unlock(&coder->mutex_coder);
}

t_coder	*ft_choose_coder_from_heap(t_dongle *dongle)
{
	t_coder	*coder_chosen;

	pthread_mutex_lock(&dongle->dongle_heap->mutex);
	if (strcmp(SCHEDULER, "fifo") == 0)
		coder_chosen = ft_fifo(dongle);
	if (strcmp(SCHEDULER, "edf") == 0)
		coder_chosen = ft_edf(dongle);
	pthread_mutex_unlock(&dongle->dongle_heap->mutex);
	return (coder_chosen);
}

void	*check_thread_state(t_coder *coder)
{
	pthread_mutex_lock(&coder->mutex_coder);
	if (coder->run == 0)
	{
		pthread_mutex_unlock(&coder->mutex_coder);
		return (NULL);
	}
	if (coder->number_of_compiles_done >= NUMBER_OF_COMPILES_REQUIRED)
	{
		pthread_mutex_unlock(&coder->mutex_coder);
		return (NULL);
	}
	pthread_mutex_unlock(&coder->mutex_coder);
	return (coder);
}
