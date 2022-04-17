/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:35:32 by hseong            #+#    #+#             */
/*   Updated: 2022/04/18 01:29:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_access_parent(const t_philo_item *item)
{
	pthread_mutex_lock(item->access);
	if (item->goal > 0
		&& philo_get_time(1) - item->recent >= item->arg.num_die)
	{
		pthread_mutex_unlock(item->access);
		return (FALSE);
	}
	pthread_mutex_unlock(item->access);
	return (TRUE);
}

t_bool	philo_access_child(t_philo_item *item)
{
	pthread_mutex_lock(item->access);
	if (item->goal > 0)
	{
		item->recent = philo_get_time(1);
		item->goal -= item->arg.num_eat;
		pthread_mutex_unlock(item->access);
		return (TRUE);
	}
	pthread_mutex_unlock(item->access);
	return (FALSE);
}
