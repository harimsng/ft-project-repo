/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/04/09 22:19:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <unistd.h>
#include <stdio.h>

inline void	philo_think(t_philo_item *const item)
{
	philo_report(THINK, item);
	pthread_mutex_lock(item->l_fork);
	pthread_mutex_lock(item->r_fork);
}

inline void	philo_eat(t_philo_item *const item)
{
	item->recent = philo_get_time(TIME_SCALE);
	philo_report(TAKE, item);
	while (item->arg->num_eat > philo_get_time(TIME_SCALE) - item->recent)
		usleep(500);
	pthread_mutex_unlock(item->l_fork);
	pthread_mutex_unlock(item->r_fork);
	item->arg->num_esc -= item->arg->num_eat * (!!item->arg->num_esc);
}

inline void	philo_sleep(t_philo_item *const item)
{
	philo_report(SLEEP, item);
	while (item->arg->num_slp + item->arg->num_eat
			> philo_get_time(TIME_SCALE) - item->recent)
		usleep(500);
}
