/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:12:39 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 13:10:36 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"

inline void	philo_think(t_philo_item *item)
{
	philo_report(M_THINK, item);
}

inline void	philo_fork(t_philo_item *item)
{
	sem_wait(item->forks);
	philo_report(M_TAKE, item);
	sem_wait(item->forks);
	philo_report(M_TAKE, item);
}

inline void	philo_eat(t_philo_item *item)
{
	philo_report(M_EAT, item);
	item->goal -= item->arg.num_eat;
	philo_msleep(item->arg.num_eat);
	sem_post(item->forks);
	sem_post(item->forks);
}

inline void	philo_sleep(t_philo_item *item)
{
	philo_report(M_SLEEP, item);
	philo_msleep(item->arg.num_slp);
}
