/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:52:35 by hseong            #+#    #+#             */
/*   Updated: 2022/04/10 02:52:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	philo_parent_job(t_philo_item *item);
static t_bool	philo_child_job(t_philo_item *item);

inline t_ms	philo_get_time(int scale)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 * scale + time.tv_usec / 1000 * scale);
}

t_bool	philo_access_recent(t_philo_item *item, t_bool who)
{
	if (item->goal <= 0)
		return (TRUE);
	pthread_mutex_lock(item->recent_access);
	if (who == PARENT)
		return (philo_parent_job(item));
	else
		return (philo_child_job(item));
}

t_bool	philo_parent_job(t_philo_item *item)
{
	t_bool	ret;

	ret = TRUE;
	if ((philo_get_time(1) - item->recent >= item->arg->num_die)
		&& (item->goal > 0))
		return (FALSE);
	pthread_mutex_unlock(item->recent_access);
	return (ret);
}

t_bool	philo_child_job(t_philo_item *item)
{
	if (item->goal <= 0)
		return (FALSE);
	item->recent = philo_get_time(1);
	pthread_mutex_unlock(item->recent_access);
	return (TRUE);
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
