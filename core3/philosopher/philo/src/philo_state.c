/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 13:40:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <unistd.h>

inline t_bool	philo_think(t_philo_item *const item)
{
	philo_report(M_THINK, item);
	return (TRUE);
}

inline t_bool	philo_lock_l(t_philo_item *const item)
{
	pthread_mutex_lock(item->l_fork);
	if (item->goal > 0)
		philo_report(M_TAKE, item);
	return (TRUE);
}

inline t_bool	philo_lock_r(t_philo_item *const item)
{
	pthread_mutex_lock(item->r_fork);
	if (item->goal > 0)
		philo_report(M_TAKE, item);
	return (TRUE);
}

inline t_bool	philo_take_eat(t_philo_item *const item)
{
	t_bool	ret;

	ret = FALSE;
	if (philo_access_recent(item, CHILD) == TRUE)
	{
		philo_report(M_EAT, item);
		philo_msleep(item->arg.num_eat);
		item->goal -= item->arg.num_eat;
		ret = TRUE;
	}
	pthread_mutex_unlock(item->l_fork);
	pthread_mutex_unlock(item->r_fork);
	return (ret);
}

inline t_bool	philo_sleep(t_philo_item *const item)
{
	philo_report(M_SLEEP, item);
	philo_msleep(item->arg.num_slp);
	return (TRUE);
}
