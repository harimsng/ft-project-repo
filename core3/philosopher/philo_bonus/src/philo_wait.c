/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_wait.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:07:27 by hseong            #+#    #+#             */
/*   Updated: 2022/04/25 23:03:53 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdio.h>
#include "philo.h"

static void	*philo_waitpid(void *arg);

static const char	*g_sem_wait = "philo_sem_monitor";

t_bool	philo_wait(t_info *info)
{
	int			ret;
	t_uint64	idx;
	t_monitor	*monitor_arr;
	t_bool		flag;
	t_fork		*sem_wait;

	idx = 0;
	flag = FALSE;
	monitor_arr = info->monitor_arr;
	sem_wait = sem_open(g_sem_wait, 0);
	while (idx < info->arg->num_philo)
	{
		monitor_arr[idx] = (t_monitor){idx, sem_wait,
			info, &flag};
		ret = pthread_create(info->thread_arr + idx, NULL, philo_waitpid,
			monitor_arr + idx);
		if (ret != 0)
		{
			philo_terminate(info, info->num, info->num);
			return (FALSE);
		}
		++idx;
	}
	idx = 0;
	while (idx < info->arg->num_philo)
	{
		pthread_join(info->thread_arr[idx], NULL);
		++idx;
	}
	return (TRUE);
}

void	*philo_waitpid(void *arg)
{
	int				state;
	t_monitor		*monitor;
	t_info			*info;
	static t_bool	dead;

	monitor = arg;
	info = monitor->info;
	waitpid(info->philo_arr[monitor->idx], &state, 0);
	printf("process join\n");
	if (WIFSIGNALED(state) || (WIFEXITED(state) && (WEXITSTATUS(state) == 0)))
		return (NULL);
	sem_wait(monitor->sem_wait);
	if (dead == FALSE)
	{
		printf("terminating\n");
		philo_terminate(info, monitor->idx, info->num);
	}
//	sem_post(info->item_arr[monitor->idx].speak);
	dead = TRUE;
	sem_post(monitor->sem_wait);
	return (NULL);
}
