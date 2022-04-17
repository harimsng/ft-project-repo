/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:06:20 by hseong            #+#    #+#             */
/*   Updated: 2022/04/16 14:42:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

static void		philo_stop(t_info *info, size_t idx);
static t_bool	philo_goal_check(t_info *info);

size_t	philo_watch(t_info *info)
{
	size_t			idx;
	size_t			len;
	t_philo_item	*item_arr;

	len = info->num;
	item_arr = info->item_arr;
	while (TRUE)
	{
		usleep(200);
		idx = 0;
		while (idx < len)
		{
			if (philo_access_parent(item_arr + idx) == FALSE)
			{
				philo_stop(info, idx);
				philo_report(M_DIE, item_arr + idx);
				pthread_mutex_unlock(item_arr[idx].access);
				return (idx + 1);
			}
			++idx;
		}
		if (philo_goal_check(info) == TRUE)
			return (0);
	}
}

void	philo_join(t_info *info, size_t	detach)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = info->num;
	while (idx < len)
	{
		if (detach - 1 == idx)
			pthread_detach(info->philo_arr[idx]);
		else
			pthread_join(info->philo_arr[idx], NULL);
		++idx;
	}
}
//		if (philo_errno != 0)
//			printf("#%zu thread join error %d\n", idx + 1, philo_errno);

void	philo_stop(t_info *info, size_t philo_idx)
{
	size_t			idx;
	size_t			len;
	t_philo_item	*item_arr;

	idx = 0;
	len = info->num;
	item_arr = info->item_arr;
	while (idx < len)
	{
		if (idx != philo_idx)
			pthread_mutex_lock(item_arr[idx].access);
		item_arr[idx].goal = 0;
		if (idx != philo_idx)
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
		ret &= item_arr[idx].goal <= 0;
		++idx;
	}
	return (ret);
}
