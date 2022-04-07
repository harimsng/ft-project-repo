/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:14:09 by hseong            #+#    #+#             */
/*   Updated: 2022/04/07 10:21:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_const.h"
#include "philo_utils.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void		*philo_eat(void *arg);
static void		philo_start(t_arg *arg, t_pack *pack);
static t_bool	philo_setup(t_pack *pack);

void	philo_dinner(t_arg *arg)
{
	t_pack	pack;
	t_philo	*philo_arr;
	t_fork	*fork_arr;
	t_pos	*pos_arr;

	philo_arr = malloc(arg->num_philo * sizeof(t_philo)),
	fork_arr = malloc(arg->num_philo * sizeof(t_fork));
	pos_arr = malloc(arg->num_philo * sizeof(t_pos));
	pack = (t_pack){arg->num_philo, philo_arr, fork_arr, pos_arr};
	if (philo_setup(&pack) == FALSE)
		return ;
	philo_start(arg, &pack);
}

t_bool	philo_setup(t_pack *pack)
{
	size_t		idx;

	if (pack->philo_arr == NULL || pack->fork_arr == NULL
			|| pack->pos_arr == NULL)
	{
		printf("memory allocation failed.\n");
		philo_dealloc(pack);
		return (FALSE);
	}
	idx = 0;
	pthread_mutex_init(pack->fork_arr + idx, NULL);
	++idx;
	while (idx < pack->num)
	{
		pthread_mutex_init(pack->fork_arr + idx, NULL);
		pack->pos_arr[idx - 1] = (t_pos){idx - 1, pack->fork_arr + idx - 1,
			pack->fork_arr + idx};
		++idx;
	}
	pack->pos_arr[idx - 1] = (t_pos){idx - 1, pack->fork_arr + idx - 1,
		pack->fork_arr};
	return (TRUE);
}

void		philo_start(t_arg *arg, t_pack *pack)
{
	size_t		idx;

	idx = 0;
	while (idx < arg->num_philo)
	{
		pos_arr[idx].arg = arg;
		pthread_create(pack->philo_arr + idx, NULL,
			philo_eat, pack->pos_arr + idx);
		++idx;
	}
	while (idx < arg->num_philo)
	{
		pthread_join(pack->philo_arr[idx], NULL);
		++idx;
	}
}

void		*philo_eat(void *arg)
{
	int		start;
	t_pos	*pos;

	start = gettimeofday();
	pos = arg;
	usleep(1000 * arg->arg->time_to_eat);
	if (pos->id % 2 == 0)
		pthread_mutex_lock(pos->l_fork);
		pthread_mutex_lock(pos->r_fork);

	printf("philosopher #%zu reports\n", pos->id);
	printf("	my left fork is %p\n", pos->l_fork);
	printf("	my right fork is %p\n", pos->r_fork);
	printf("	i'm eating dinner\n");
	pthread_mutex_unlock(pos->l_fork);
	pthread_mutex_unlock(pos->r_fork);
	return (NULL);
}