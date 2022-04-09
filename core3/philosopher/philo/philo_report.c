/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:48:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/09 22:22:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static const char	*g_report[]
= {
	"taken a fork",
	"is eating",
	"is sleeping",
	"is thinking",
	"died",
};

void	philo_report(int idx, const t_philo_item *const item)
{
	static t_fork	speak;
	static t_bool	init;
	static t_ms		time;

	if (init == FALSE)
	{
		pthread_mutex_init(&speak, NULL);
		init = TRUE;
	}
	pthread_mutex_lock(&speak);
	time = philo_get_time(TIME_SCALE) - item->init_time;
	printf("%7lld %3zu %s\n", time, item->id, g_report[idx]);
	if (idx == TAKE)
		printf("%7lld %3zu %s\n", time, item->id, g_report[EAT]);
	if (item->goal <= 0 && idx == DIE)
		return ;
	pthread_mutex_unlock(&speak);
}
