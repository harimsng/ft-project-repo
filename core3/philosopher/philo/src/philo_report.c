/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:48:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/18 01:36:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static const char *const	g_report[] = {
	"is thinking",
	"taken a fork",
	"is eating",
	"is sleeping",
	"died",
};

// item->goal must be signed integer
void	philo_report(int idx, t_philo_item *item)
{
	if (idx != M_DIE)
	{
		pthread_mutex_lock(item->speak);
		if (item->goal <= -(t_int64)((idx == M_EAT) * item->arg.num_eat))
		{
			pthread_mutex_unlock(item->speak);
			return ;
		}
	}
	printf("%8lld %3zu %s\n",
		philo_get_time(TIME_SCALE) - item->init_time * TIME_SCALE,
		item->id, g_report[idx]);
	pthread_mutex_unlock(item->speak);
}
