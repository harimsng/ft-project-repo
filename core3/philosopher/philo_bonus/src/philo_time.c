/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:52:58 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 12:24:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

t_ms	philo_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	philo_ready(t_philo_item *item)
{
	t_ms	init_time;

	init_time = item->init_time;
	while (philo_get_time() < init_time)
		usleep(100);
}

void	philo_msleep(t_ms ms)
{
	t_ms	start;

	start = philo_get_time();
	while (philo_get_time() - start < ms)
		usleep(100);
}
