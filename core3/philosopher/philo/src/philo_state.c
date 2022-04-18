/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 03:25:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <unistd.h>

inline void	philo_think(t_philo_item *const item)
{
	philo_report(M_THINK, item);
}

inline void	philo_lock_r(t_philo_item *const item)
{
	pthread_mutex_lock(item->r_fork);
	philo_report(M_TAKE, item);
}

inline void	philo_lock_l(t_philo_item *const item)
{
	pthread_mutex_lock(item->l_fork);
	philo_report(M_TAKE, item);
}

inline void	philo_take_eat(t_philo_item *const item)
{
	if (philo_access_child(item) == TRUE)
	{
		philo_report(M_EAT, item);
		philo_msleep(item->arg.num_eat);
	}
	pthread_mutex_unlock(item->l_fork);
	pthread_mutex_unlock(item->r_fork);
}

inline void	philo_sleep(t_philo_item *const item)
{
	philo_report(M_SLEEP, item);
	philo_msleep(item->arg.num_slp);
}
