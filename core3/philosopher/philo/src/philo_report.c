/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:48:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 14:27:46 by hseong           ###   ########.fr       */
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

void	philo_report(int idx, const t_philo_item *const item)
{
	t_ms		time;

	pthread_mutex_lock(item->speak);
	if (idx != M_DIE && item->goal <= 0)
	{
		pthread_mutex_unlock(item->speak);
		return ;
	}
	time = philo_get_time(TIME_SCALE) - item->init_time * TIME_SCALE;
	printf("%8lld %3zu %s\n", time, item->id, g_report[idx]);
	pthread_mutex_unlock(item->speak);
	if (idx == M_DIE)
		pthread_mutex_destroy(item->speak);
}
