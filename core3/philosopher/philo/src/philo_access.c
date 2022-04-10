/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:35:32 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 00:20:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_parent_job(t_philo_item *item);
static t_bool	philo_child_job(t_philo_item *item);

t_bool	philo_access_recent(t_philo_item *item, t_bool who)
{
	pthread_mutex_lock(item->access);
	if (who == PARENT)
		return (philo_parent_job(item));
	else
		return (philo_child_job(item));
}

t_bool	philo_parent_job(t_philo_item *item)
{
	if ((philo_get_time(1) - item->recent >= item->arg->num_die)
		&& (item->goal > 0))
		return (FALSE);
	pthread_mutex_unlock(item->access);
	return (TRUE);
}

t_bool	philo_child_job(t_philo_item *item)
{
	if (item->goal <= 0)
	{
		pthread_mutex_unlock(item->access);
		return (FALSE);
	}
	item->recent = philo_get_time(1);
	pthread_mutex_unlock(item->access);
	return (TRUE);
}
