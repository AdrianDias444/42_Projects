/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coder_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 19:00:01 by adrian            #+#    #+#             */
/*   Updated: 2026/08/04 13:19:34 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_wait_dongle_be_free(t_dongle *dongle, t_coder *coder)
{
	long	duration;
	int		run_status;

	pthread_mutex_lock(&coder->mutex_coder);
	run_status = coder->run;
	pthread_mutex_unlock(&coder->mutex_coder);
	ft_heap_push_back(dongle->dongle_heap, coder);
	pthread_mutex_lock(&dongle->mutex);
	while (ft_choose_coder_from_heap(dongle) != coder && run_status == 1)
		if (dongle->actual_coder)
			pthread_cond_wait(&dongle->cond, &dongle->mutex);
	if (run_status == 0)
	{
		ft_remove_from_heap(dongle->dongle_heap, coder);
		pthread_cond_signal(&dongle->cond);
		pthread_mutex_unlock(&dongle->mutex);
		return (0);
	}
	duration = ft_return_time_since_start(coder->start_ms);
	pthread_mutex_lock(&coder->simulation->mutex);
	printf("%ld %d has taken a dongle\n", duration, coder->number);
	pthread_mutex_unlock(&coder->simulation->mutex);
	dongle->actual_coder = coder;
	pthread_mutex_unlock(&dongle->mutex);
	return (1);
}

void	set_actual_coder_null(t_dongle *dongle, long timetwait)
{
	pthread_mutex_lock(&dongle->mutex);
	dongle->actual_coder = NULL;
	pthread_cond_signal(&dongle->cond);
	if (timetwait > 0)
		usleep(timetwait);
	pthread_mutex_unlock(&dongle->mutex);
}

int	coder_cicle(t_coder *coder, t_dongle *first, t_dongle *second)
{
	while (1)
	{
		if (!check_thread_state(coder))
			break ;
		if (!ft_wait_dongle_be_free(first, coder))
			return (0);
		ft_remove_from_heap(first->dongle_heap, coder);
		ft_print_dongle_heap(&coder->simulation->mutex, first);
		if (!ft_wait_dongle_be_free(second, coder))
			return (0);
		ft_remove_from_heap(second->dongle_heap, coder);
		ft_print_dongle_heap(&coder->simulation->mutex, second);
		ft_compile(coder);
		set_actual_coder_null(first, first->dongle_cooldown * 1000);
		set_actual_coder_null(second, 0);
		ft_debug(coder);
		ft_refactor(coder);
	}
	return (1);
}

void	*coder_rotine(void *arg)
{
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_dongle	*first;
	t_dongle	*second;
	t_coder		*coder;

	coder = (t_coder *) arg;
	left_dongle = coder->left_dongle;
	right_dongle = coder->right_dongle;
	first = left_dongle;
	second = right_dongle;
	if (first->name > second->name)
	{
		first = right_dongle;
		second = left_dongle;
	}
	coder_cicle(coder, first, second);
	pthread_mutex_lock(&coder->mutex_coder);
	coder->action = "done";
	pthread_mutex_unlock(&coder->mutex_coder);
	return (NULL);
}

void	ft_create_coder_thread(t_coder *coder, pthread_t *thread)
{
	pthread_create(thread, NULL, coder_rotine, coder);
}
