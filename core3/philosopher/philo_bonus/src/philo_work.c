/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:37 by hseong            #+#    #+#             */
/*   Updated: 2022/04/22 22:29:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <stdio.h>

static void		philo_work_init(t_philo_item *item, pthread_t *monitor);
static void		philo_work_end(t_philo_item *item, pthread_t *monitor, int state);
static void		*philo_monitor(void *arg);
static t_bool	philo_access(t_philo_item *item);

t_bool	philo_work(t_philo_item *item)
{
	int			state;
	pthread_t	monitor;

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
	philo_work_end(item, &monitor,
		(state + 2 * PHILO_STATES - 1) % PHILO_STATES);
	return (item->recent == 0);
}

void	philo_work_init(t_philo_item *item, pthread_t *monitor)
{
	item->forks = sem_open(g_sem_forks, 0);
	item->access = sem_open(g_sem_access, 0);
	item->speak = sem_open(g_sem_speak, 0);
	if (pthread_create(monitor, NULL, philo_monitor, item) != 0)
	{
		printf("monitoring thread creation failed\n");
		item->goal = 0;
	}
	philo_ready(item);
	item->recent = item->init_time;
	if (item->id % 2 == 1)
		philo_msleep(item->arg.num_eat / 2);
}

void	philo_work_end(t_philo_item *item, pthread_t *monitor, int state)
{
	if (state == S_FORK)
	{
		sem_post(item->forks);
		sem_post(item->forks);
	}
	sem_close(item->forks);
	sem_close(item->access);
	sem_close(item->speak);
	pthread_join(*monitor, NULL);
}

void	*philo_monitor(void *arg)
{
	t_philo_item	*item;

	item = arg;
	philo_ready(item);
	while (item->goal > 0)
	{
		philo_msleep(1);
		if (philo_access(item))
		{
			item->recent = 0;
			item->goal = 0;
			sem_wait(item->speak);
			sem_post(item->access);
			philo_report(M_DIE, item);
			return (NULL);
		}
	}
	return (NULL);
}

t_bool	philo_access(t_philo_item *item)
{
	sem_wait(item->access);
	if (philo_get_time() - item->recent >= item->arg.num_die)
		return (TRUE);
	sem_post(item->access);
	return (FALSE);
}
