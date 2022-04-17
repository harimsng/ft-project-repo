/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:25:04 by hseong            #+#    #+#             */
/*   Updated: 2022/04/16 14:35:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

static void			*philo_work(void *arg);
static t_bool		philo_make(t_info *info);
static t_philo_item	*philo_work_init(t_philo_item *item, t_fork *access);
static void			philo_work_end(t_philo_item *item, int state);

t_bool	philo_dinner(t_arg *arg, t_info *info)
{
	size_t	num;

	num = arg->num_philo;
	info->num = num;
	if (philo_alloc(num, info) == FALSE
		|| philo_setup(arg, info) == FALSE
		|| philo_make(info) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	philo_make(t_info *info)
{
	size_t			idx;
	t_ms			init_time;

	init_time = philo_get_time(1) + info->num;
	idx = 0;
	while (idx < info->num)
	{
		info->item_arr[idx].init_time = init_time;
		info->item_arr[idx].recent = init_time;
		if (pthread_create(info->philo_arr + idx, NULL,
				philo_work, info->item_arr + idx) != 0)
		{
			printf("threads creation failed.\n");
			philo_mutex_destroy(idx, info);
			philo_dealloc(info);
			return (FALSE);
		}
		++idx;
	}
	philo_ready(info->item_arr);
	philo_msleep(info->item_arr->arg.num_die / 2);
	return (TRUE);
}

void	*philo_work(void *arg)
{
	t_philo_item	*item;
	t_fork			access;
	int				state;

	item = philo_work_init(arg, &access);
	pthread_mutex_lock(item->access);
	state = -(item->goal <= 0);
	pthread_mutex_unlock(item->access);
	while (state > -1)
	{
		g_philo_state[state](item);
		++state;
		state %= PHILO_STATES;
		pthread_mutex_lock(item->access);
		state -= PHILO_STATES * (item->goal <= 0);
		pthread_mutex_unlock(item->access);
	}
	philo_work_end(item, state - 1);
	return (NULL);
}
//	printf("[#%5zu] ", item->id);

t_philo_item	*philo_work_init(t_philo_item *item, t_fork *access)
{
	pthread_mutex_init(access, NULL);
	item->access = access;
	philo_ready(item);
	item->recent = item->init_time;
	if (item->id % 2 == 1)
		philo_msleep(item->arg.num_eat / 2);
	return (item);
}

void	philo_work_end(t_philo_item *item, int state)
{
	if (state == S_LOCK_L || state == S_LOCK_R)
		pthread_mutex_unlock(item->r_fork);
	if (state == S_LOCK_L)
		pthread_mutex_unlock(item->l_fork);
	philo_msleep(item->arg.num_philo * 2);
	pthread_mutex_destroy(item->access);
}
