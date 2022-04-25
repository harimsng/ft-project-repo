/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:37 by hseong            #+#    #+#             */
/*   Updated: 2022/04/25 23:21:19 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <stdio.h>

static void		philo_work_init(t_philo_item *item);
static void		philo_work_end(t_philo_item *item, int state);
static void		*philo_work(void *arg);
static t_bool	philo_access(t_philo_item *item);

static const char	*g_sem_forks = "philo_sem_forks";
static const char	*g_sem_speak = "philo_sem_speak";
static const char	*g_sem_access = "philo_sem_access";

t_bool	philo_create(t_philo_item *item)
{
	t_thread	worker;

	if (pthread_create(&worker, NULL, philo_work, item) != 0)
	{
		printf("monitoring thread creation failed\n");
		item->recent = 0;
		item->goal = 0;
	}
	philo_ready(item);
	while (item->goal > 0)
	{
		philo_msleep(1);
		if (philo_access(item))
		{
			printf("%zu dead\n", item->id);
			item->recent = 0;
			item->goal = 0;
			sem_wait(item->speak);
			philo_report(M_DIE, item);
		}
	}
	pthread_join(worker, NULL);
	return (item->recent == 0);
}

void	*philo_work(void *arg)
{
	t_philo_item	*item;
	int				state;

	item = arg;
	philo_work_init(item);
	state = 0;
	while (state > -1)
	{
		g_philo_state[state++](item);
		state %= PHILO_STATES;
		sem_wait(item->access);
		state -= PHILO_STATES * (item->goal <= 0);
		sem_post(item->access);
	}
	philo_work_end(item, (state + 2 * PHILO_STATES - 1) % PHILO_STATES);
	return (NULL);
}

void	philo_work_init(t_philo_item *item)
{
	item->forks = sem_open(g_sem_forks, 0);
	item->access = sem_open(g_sem_access, 0);
	item->speak = sem_open(g_sem_speak, 0);
	philo_ready(item);
	item->recent = item->init_time;
	if (item->id % 2 == 1)
		philo_msleep(item->arg.num_eat / 2);
}

void	philo_work_end(t_philo_item *item, int state)
{
	if (state == S_FORK)
	{
		sem_post(item->forks);
		sem_post(item->forks);
	}
	sem_close(item->forks);
	sem_close(item->access);
	sem_close(item->speak);
}

t_bool	philo_access(t_philo_item *item)
{
			printf("%zu access wait\n", item->id);
	sem_wait(item->access);
			printf("%zu access acquired\n", item->id);
	if (philo_get_time() - item->recent >= (t_ms)item->arg.num_die)
		return (TRUE);
	sem_post(item->access);
			printf("%zu access post\n", item->id);
	return (FALSE);
}
