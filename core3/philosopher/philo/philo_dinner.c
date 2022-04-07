/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:14:09 by hseong            #+#    #+#             */
/*   Updated: 2022/04/07 22:03:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

static void		*philo_eat(void *arg);
static void		philo_start(t_arg *arg, t_info *info);

void	philo_dinner(t_arg *arg)
{
	size_t	num;
	t_info	info;

	num = arg->num_philo;
	info.num = num;
	if (philo_alloc(num, &info) == FALSE)
		return ;
	if (philo_setup(arg, &info) == FALSE)
		return ;
	philo_start(arg, &info);
}

void		philo_start(t_arg *arg, t_info *info)
{
	size_t	idx;
	t_ms	init_time;

	init_time = philo_get_time();
	idx = 0;
	while (idx < arg->num_philo)
	{
		info->item_arr[idx].init_time = init_time;
		if (pthread_create(info->philo_arr + idx, NULL,
			philo_eat, info->item_arr + idx) != 0)
		{
			printf("threads creation failed.\n");
			philo_destroy(idx, info);
			break ;
		}
		++idx;
	}
	while (idx > 0)
	{
		pthread_join(info->philo_arr[idx - 1], NULL);
		--idx;
	}
}

void		*philo_eat(void *arg)
{
	t_philo_item	item;
	size_t			len = 3;

	item = *(t_philo_item *)arg;
	while (len-- > 0)
	{
		philo_report(THINK, item.id, item.init_time);
		pthread_mutex_lock(item.l_fork);
		pthread_mutex_lock(item.r_fork);
		philo_report(TAKE, item.id, item.init_time);
		philo_report(EAT, item.id, item.init_time);
		philo_eating(item.arg->num_eat);
		pthread_mutex_unlock(item.l_fork);
		pthread_mutex_unlock(item.r_fork);
		philo_report(SLEEP, item.id, item.init_time);
		philo_sleeping(item.arg->num_slp);
	}
	return (NULL);
}
