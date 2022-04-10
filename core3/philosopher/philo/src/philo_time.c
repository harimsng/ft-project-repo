/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:52:35 by hseong            #+#    #+#             */
/*   Updated: 2022/04/10 23:48:42 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

inline t_ms	philo_get_time(int scale)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 * scale + time.tv_usec / 1000 * scale);
}

inline void	philo_msleep(t_ms time)
{
	t_ms	start;

	start = philo_get_time(1);
	while (start + time > philo_get_time(1))
		usleep(500);
}

void	philo_ready(const t_philo_item *const item)
{
	t_ms	time;
	t_ms	start_time;

	start_time = item->init_time;
	time = philo_get_time(1);
	while (time < start_time)
		time = philo_get_time(1);
}
