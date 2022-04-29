/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:37 by hseong            #+#    #+#             */
/*   Updated: 2022/04/29 22:31:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <stdio.h>
#if __linux__
# include <fcntl.h>
#endif

static t_bool	philo_work_init(t_philo_item *item, t_thread *worker);
static void		philo_work_end(t_philo_item *item, int state);
static void		*philo_work(void *arg);
static int		philo_access(t_philo_item *item);

static const char	*g_sem_forks = "/philo_sem_forks";
static const char	*g_sem_speak = "/philo_sem_speak";
static const char	*g_sem_access = "/philo_sem_access";

t_bool	philo_create(t_philo_item *item)
{
	t_thread	worker;
	int			ret;

	philo_work_init(item, &worker);
	philo_ready(item);
	while (TRUE)
	{
		philo_msleep(1);
		ret = philo_access(item);
		if (ret == 1)
		{
			item->recent = 0;
			item->goal = 0;
			sem_wait(item->speak);
			sem_post(item->access);
			philo_report(M_DIE, item);
			pthread_detach(worker);
			return (1);
		}
		else if (ret == 2)
			break ;
	}
	pthread_join(worker, NULL);
	return (0);
}

void	*philo_work(void *arg)
{
	t_philo_item	*item;
	int				state;

	item = arg;
	philo_ready(item);
	if (item->id % 2 == 1)
		philo_msleep(item->arg.num_eat / 2);
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

t_bool	philo_work_init(t_philo_item *item, t_thread *worker)
{
	item->forks = sem_open(g_sem_forks, O_CREAT, 0666, item->arg.num_philo);
	item->access = sem_open(g_sem_access, O_CREAT, 0666, 1);
	item->speak = sem_open(g_sem_speak, O_CREAT, 0666, 1);
	if (item->forks == SEM_FAILED
		|| item->access == SEM_FAILED
		|| item->speak == SEM_FAILED)
	{
		printf("sem_open failed\n");
		return (FALSE);
	}
	if (pthread_create(worker, NULL, philo_work, item) != 0)
	{
		printf("monitoring thread creation failed\n");
		return (FALSE);
	}
	return (TRUE);
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

int	philo_access(t_philo_item *item)
{
	sem_wait(item->access);
	if (philo_get_time() - item->recent >= (t_ms)item->arg.num_die)
		return (1);
	else if (item->goal <= 0)
	{
		sem_post(item->access);
		return (2);
	}
	sem_post(item->access);
	return (0);
}
