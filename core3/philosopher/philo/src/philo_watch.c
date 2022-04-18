/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:06:20 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 04:29:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
# include <stdio.h>

static void		philo_stop(t_info *info);
static t_bool	philo_goal_check(t_info *info);

void	philo_watch(t_info *info)
{
	t_philo_item	*item_arr;
	size_t			idx;
	size_t			len;

	item_arr = info->item_arr;
	len = info->num;
	while (TRUE)
	{
		idx = 0;
		while (idx < len)
		{
			if (philo_access_parent(info->item_arr + idx) == FALSE)
			{
				philo_stop(info);
				philo_report(M_DIE, info->item_arr + idx);
				return ;
			}
			++idx;
		}
		if (philo_goal_check(info) == TRUE)
			return ;
		usleep(100);
	}
}
// dead thread is not terminated when the program have parent(ex. debbuger)
void	philo_join(t_info *info)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = info->num;
	while (idx < len)
	{
		pthread_join(info->philo_arr[idx], NULL);
		++idx;
	}
}
//		if (philo_errno != 0)
//			printf("#%zu thread join error %d\n", idx + 1, philo_errno);

void	philo_stop(t_info *info)
{
	size_t			idx;
	size_t			len;
	t_philo_item	*item_arr;

	idx = 0;
	len = info->num;
	item_arr = info->item_arr;
	while (idx < len)
	{
		pthread_mutex_lock(item_arr[idx].access);
		item_arr[idx].goal = INT_MIN;
		pthread_mutex_unlock(item_arr[idx].access);
		++idx;
	}
}

t_bool	philo_goal_check(t_info *info)
{
	size_t			idx;
	size_t			len;
	t_philo_item	*item_arr;
	t_bool			ret;

	idx = 0;
	len = info->num;
	item_arr = info->item_arr;
	ret = TRUE;
	while (idx < len)
	{
		pthread_mutex_lock(item_arr[idx].access);
		ret &= item_arr[idx].goal <= 0;
		pthread_mutex_unlock(item_arr[idx].access);
		++idx;
	}
	return (ret);
}

/*
typedef struct s_monitor
{
	size_t		idx;
	size_t		len;
	t_info		*info;
	t_bool		*flag;
}				t_monitor;

static void		*philo_monitor(void *arg);

void	philo_watch(t_info *info)
{
	size_t			idx;
	size_t			len;
	t_monitor		monitor_arg[MAX_MONITOR];
	pthread_t		monitor_threads[MAX_MONITOR];
	static t_bool	flag = TRUE;

	len = (info->num + PER_MONITOR - 1) / PER_MONITOR;
	idx = 0;
	while (idx < len - 1)
	{
		monitor_arg[idx] = (t_monitor){idx, PER_MONITOR, info, &flag};
		pthread_create(monitor_threads + idx, NULL,
			philo_monitor, monitor_arg + idx);
		++idx;
	}
	monitor_arg[idx] = (t_monitor){idx, info->num % PER_MONITOR, info, &flag};
	pthread_create(monitor_threads + idx, NULL,
		philo_monitor, monitor_arg + idx);
	philo_ready(info->item_arr);
	philo_msleep(info->item_arr->arg.num_die / 2);
	idx = 0;
	while (idx < len)
		pthread_join(monitor_threads[idx++], NULL);
	philo_stop(info);
	philo_report(M_DIE, info->item_arr + idx);
}

void		*philo_monitor(void *arg)
{
	t_monitor		*monitor;
	t_info			*info;
	size_t			idx;

	monitor = arg;
	info = monitor->info;
	while (*monitor->flag)
	{
		idx = 0;
		while (idx < monitor->len)
		{
			if (philo_access_parent(info->item_arr
				+ idx + monitor->idx * PER_MONITOR) == FALSE)
			{
				*monitor->flag = 0;
				return (NULL);
			}
			++idx;
		}
		if (philo_goal_check(info) == TRUE)
			*monitor->flag = 0;
	}
	return (NULL);
}
*/
