/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:11:11 by adrian            #+#    #+#             */
/*   Updated: 2026/08/04 10:57:56 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef NUMBER_OF_CODERS
#  define NUMBER_OF_CODERS 3
# endif

# ifndef TIME_TO_BURNOUT
#  define TIME_TO_BURNOUT 800
# endif

# ifndef TIME_TO_COMPILE
#  define TIME_TO_COMPILE 150
# endif

# ifndef TIME_TO_DEBUG
#  define TIME_TO_DEBUG 450
# endif

# ifndef TIME_TO_REFACTOR
#  define TIME_TO_REFACTOR 300
# endif

# ifndef NUMBER_OF_COMPILES_REQUIRED
#  define NUMBER_OF_COMPILES_REQUIRED 2
# endif

# ifndef DONGLE_COOLDOWN
#  define DONGLE_COOLDOWN 10
# endif

# ifndef SCHEDULER
#  define SCHEDULER "edf"
# endif

typedef struct s_dongle		t_dongle;
typedef struct s_simulation	t_simulation;

typedef struct arguments
{
	int						number_of_coders;
	int						time_to_burnout;
	int						time_to_compile;
	int						time_to_debug;
	int						time_to_refactor;
	int						number_of_compiles_required;
	int						dongle_cooldown;
	char					*scheduler;
	long					start_ms;
}							t_args;

typedef struct coder
{
	int						run;
	int						number;
	struct coder			*next;
	struct coder			*previous;
	char					*action;
	t_dongle				*right_dongle;
	t_dongle				*left_dongle;
	long						time_to_compile;
	long						time_to_debug;
	long						time_to_refactor;
	long						time_to_burnout;
	long					start_ms;
	pthread_t				coder_thread_id;
	long					time_of_last_compile;
	t_simulation			*simulation; // SIMULATION
	long					number_of_compiles_done;
	struct coder			*heap_next;
	pthread_mutex_t			mutex_coder;

}							t_coder;

typedef struct circle
{
	t_coder					*first_coder;
	int						number_of_coders;
	int						nb_dongles;
	long					number_of_compiles_required;
	long					dongle_cooldown;
}							t_circle;

typedef struct heap
{
	t_coder					*first;
	long					how_many_waiting;
	pthread_mutex_t			mutex;
}							t_heap;

struct						s_dongle
{
	t_coder					*actual_coder;
	struct s_dongle			*next;
	char					name;
	pthread_mutex_t			mutex; // MUTEX
	pthread_cond_t			cond;
	long					dongle_cooldown;
	t_heap					*dongle_heap;
};

struct						s_simulation
{
	pthread_mutex_t			mutex;
};

t_args		ft_parser(void);
void		ft_add_next_coder(t_coder *current, t_coder *next);
void		ft_add_previous_coder(t_coder *current, t_coder *previous);
t_coder		*ft_create_coder(int nb);
t_circle	*ft_handle_circle(t_args args);
void		ft_print_args(t_args args);
void		ft_print_circle(t_coder *first_coder);
t_circle	*ft_create_circle(t_coder *coder, t_args args);
void		*ft_handle_dongles(t_circle *circle);
void		ft_print_dongles(t_circle *circle);
void		ft_add_dongle_right(t_coder *coder,	t_dongle *dongle);
void		ft_add_dongle_left(t_coder *coder,	t_dongle *dongle);
void		ft_add_times(t_args args, t_coder *coder);
void		ft_create_coder_thread(t_coder *coder, pthread_t *thread);
long		ft_return_time_since_start(long start_ms);
long		ft_return_time_now(void);
void		ft_create_monitor_thread(t_circle *circle, pthread_t *thread);
t_dongle	*ft_create_dongle(void);
t_heap		*ft_create_heap(void);
void		ft_heap_push_back(t_heap *heap, t_coder *coder_to_push_back);
void		ft_remove_from_heap(t_heap *heap, t_coder *coder);
void		ft_print_dongle_heap(pthread_mutex_t *mutex, t_dongle *dongle);
t_coder		*return_first_coder(t_heap *heap);
t_coder		*ft_edf(t_dongle *dongle);
t_coder		*ft_fifo(t_dongle *dongle);




void	ft_compile(t_coder	*coder);
void	ft_debug(t_coder *coder);
void	ft_refactor(t_coder	*coder);
t_coder	*ft_choose_coder_from_heap(t_dongle *dongle);


#endif