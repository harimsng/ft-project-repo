/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:35:32 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 14:24:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_parent_job(const t_philo_item *item);
static t_bool	philo_child_job(t_philo_item *item);

t_bool	philo_access_recent(const t_philo_item *item, t_bool who)
{
	pthread_mutex_lock(item->access);
	if (who == PARENT)
		return (philo_parent_job(item));
	else
		return (philo_child_job((t_philo_item *)item));
}

t_bool	philo_parent_job(const t_philo_item *item)
{
	if ((item->goal > 0)
		&& (philo_get_time(1) - item->recent >= item->arg.num_die))
		return (FALSE);
	pthread_mutex_unlock(item->access);
	return (TRUE);
}

t_bool	philo_child_job(t_philo_item *item)
{
	if (item->goal > 0)
	{
		item->recent = philo_get_time(1);
		return (TRUE);
	}
	pthread_mutex_unlock(item->access);
	return (FALSE);
}
