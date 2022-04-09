/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:52:35 by hseong            #+#    #+#             */
/*   Updated: 2022/04/09 22:16:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

inline t_ms	philo_get_time(int scale)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 * scale + time.tv_usec / 1000 * scale);
}

/*
t_ms	philo_get_recent(t_philo_item *item)
{
	static pthread_mutex_t	mtx;
	static t_bool			init;

	if (init == FALSE)
	{
		pthread_mutex_init(&mtx, NULL);
		init = TRUE;
	}
	pthread_mutex_lock(&mtx);
	
	pthread_mutex_unlock(&mtx);
}
*/

void	philo_ready(const t_philo_item * const item)
{
	t_ms	time;
	t_ms	start_time;

	start_time = item->init_time;
	time = philo_get_time(1);
	while (time < start_time)
		time = philo_get_time(1);
}
