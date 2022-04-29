/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:40:40 by hseong            #+#    #+#             */
/*   Updated: 2022/04/27 20:48:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <stdio.h>

#define MONITOR_INTERVAL (1)

void			*philo_work(void *arg);
void			philo_exit(t_philo_item *item);
static int		philo_access(t_philo_item *item);
static t_bool	philo_init(t_philo_item *item, t_thread *worker);

static const char	*g_sem_forks = "philo_sem_forks";
static const char	*g_sem_speak = "philo_sem_speak";
static const char	*g_sem_access = "philo_sem_access";

t_bool	philo_create(t_philo_item *item)
{
	t_thread	worker;
	int			ret;
	
	philo_init(item, &worker);
	philo_ready(item);
	while (TRUE)
	{
		philo_msleep(MONITOR_INTERVAL);
		ret = philo_access(item);
		if (ret == 1)
		{
			item->recent = 0;
			item->goal = 0;
			sem_wait(item->speak);
			sem_post(item->access);
			philo_report(M_DIE, item);
//			philo_exit(item);
//		return (1);
			break ;
		}
		else if (ret == 2)
			break ;
	}
	pthread_join(worker, NULL);
//	philo_exit(item);
	return (item->recent == 0);
}

t_bool	philo_init(t_philo_item *item, t_thread *worker)
{
	item->forks = sem_open(g_sem_forks, 0);
	item->access = sem_open(g_sem_access, 0);
	item->speak = sem_open(g_sem_speak, 0);
	if (pthread_create(worker, NULL, philo_work, item) != 0)
	{
		printf("monitoring thread creation failed\n");
		return (FALSE);
	}
	return (TRUE);
}

int	philo_access(t_philo_item *item)
{
	sem_wait(item->access);
	if (philo_get_time()
			>= (t_ms)item->arg.num_die + item->recent)
		return (1);
	else if (item->goal <= 0)
	{
		sem_post(item->access);
		return (2);
	}
	sem_post(item->access);
	return (0);
}
