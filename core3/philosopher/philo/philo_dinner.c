/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:14:09 by hseong            #+#    #+#             */
/*   Updated: 2022/04/09 21:53:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

static void		*philo_work(void *arg);
static t_bool	philo_make(t_info *info);

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

	init_time = philo_get_time(TIME_SCALE) + info->num;
	idx = 0;
	while (idx < info->num)
	{
		info->item_arr[idx].init_time = init_time;
		if (pthread_create(info->philo_arr + idx, NULL,
			philo_work, info->item_arr + idx) != 0)
		{
			printf("threads creation failed.\n");
			philo_destroy(idx, info);
			return (FALSE);
		}
		++idx;
	}
	philo_ready(info->item_arr);
	usleep(info->num * 100);
	return (TRUE);
}

void	*philo_work(void *arg)
{
	t_philo_item	*item;
	int				state;

	item = (t_philo_item *)arg;
	philo_ready(item);
	item->recent = item->init_time;
	if (item->id % 2 == 0)
		usleep(item->arg->num_eat * 500);
	state = 0;
	while (item->recent && item->goal > 0)
	{
		g_philo_state[state++](item);
		state %= 3;
	}
	return (NULL);
}
