/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:35:32 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 04:26:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
# include <stdio.h>

inline t_bool	philo_access_parent(const t_philo_item *item)
{
	pthread_mutex_lock(item->access);
	if (philo_get_time(1) - item->recent >= item->arg.num_die
		&& item->goal > 0)
	{
		pthread_mutex_lock(item->speak);
		pthread_mutex_unlock(item->access);
		return (FALSE);
	}
	pthread_mutex_unlock(item->access);
	return (TRUE);
}

t_bool	philo_access_child(t_philo_item *item)
{
	t_ms	time;

	time = philo_get_time(1);
	pthread_mutex_lock(item->access);
	if (time - item->recent < item->arg.num_die
		&& item->goal > 0)
	{
		item->recent = time;
		item->goal -= item->arg.num_eat;
		pthread_mutex_unlock(item->access);
		return (TRUE);
	}
	pthread_mutex_unlock(item->access);
	return (FALSE);
}
