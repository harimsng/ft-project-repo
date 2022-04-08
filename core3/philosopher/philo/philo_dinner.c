/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:14:09 by hseong            #+#    #+#             */
/*   Updated: 2022/04/08 17:38:39 by hseong           ###   ########.fr       */
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
static void		philo_start(t_info *info);

void	philo_dinner(t_arg *arg)
{
	size_t	num;
	t_info	info;

	num = arg->num_philo;
	info.num = num;
	if (philo_alloc(num, &info) == FALSE
		|| philo_setup(arg, &info) == FALSE)
		return ;
	philo_start(&info);
	philo_watch(&info);
}

void	philo_start(t_info *info)
{
	size_t	idx;
	t_ms	init_time;

	init_time = philo_get_time() + info->item_arr->arg.num_philo;
	idx = 0;
	while (idx < info->num)
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
}

void	*philo_eat(void *arg)
{
	t_philo_item	*item = (t_philo_item *)arg;
	size_t			len = 3;

	philo_ready(item);
	if (item->id % 2 == 0)
		usleep(item->arg.num_eat * 500);
	while (--len)
	{
		philo_report(THINK, item);
		item->recent = pthread_mutex_lock(item->l_fork);
		pthread_mutex_lock(item->r_fork);
		philo_report(TAKE, item);
		philo_report(EAT, item);
		philo_eating(item);
		pthread_mutex_unlock(item->l_fork);
		pthread_mutex_unlock(item->r_fork);
		philo_report(SLEEP, item);
		philo_sleeping(item);
	}
	return (NULL);
}
