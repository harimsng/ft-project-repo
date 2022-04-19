/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:37 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 13:43:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"

static void	philo_work_init(t_philo_item *item, pthread_t *monitor);
static void	*philo_monitor(void *arg);

static const char	*g_sem_access = "philo_access";

void	philo_work(t_philo_item *item)
{
	int			state;
	pthread_t	monitor;

	item->access = sem_open(g_sem_access, O_CREAT, 0666, 1);
	if (item->access == SEM_FAILED)
//		item->goal = 0;
	philo_work_init(item, &monitor);
	state = 0;
	while (state > -1)
	{
		g_philo_state[state++](item);
		state %= PHILO_STATES;
		sem_wait(item->access);
		state -= PHILO_STATES * (item->goal <= 0);
		sem_post(item->access);
	}
}

void	philo_work_init(t_philo_item *item, pthread_t *monitor)
{
	pthread_create(monitor, NULL, philo_monitor, item);
	philo_ready(item);
	philo_msleep(item->arg.num_philo / 2);
}

void	*philo_monitor(void *arg)
{
	t_philo_item	*item;

	item = arg;
	while (TRUE)
	{
		philo_msleep(1);
		if (philo_get_time() - item->recent >= item->arg.num_die)
		{
			item->goal = 0;
			return (NULL);
		}
	}
	return (NULL);
}
