/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:06:20 by hseong            #+#    #+#             */
/*   Updated: 2022/04/10 02:22:48 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	philo_watch(t_info *info)
{
	size_t			idx;
	size_t			len;
	t_philo_item	*item_arr;

	len = info->num;
	item_arr = info->item_arr;
	while (TRUE)
	{
		idx = 0;
		while (idx < len)
		{
			if (philo_access_recent(item_arr + idx, PARENT) == FALSE)
			{
				philo_stop(info);
				philo_report(DIE, item_arr + idx);
				if (item_arr[idx].goal > 0)
					pthread_mutex_unlock(item_arr[idx].recent_access);
				return ;
			}
			++idx;
		}
		if (philo_goal_check(info) == TRUE)
			return ;
	}
}
//printf("actual death time = %lld\n", temp_time - item_arr[idx].init_time);

void	philo_join(t_info *info)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = info->num;
	while (idx < len)
	{
		pthread_detach(info->philo_arr[idx]);
		pthread_join(info->philo_arr[idx], NULL);
		++idx;
	}
}

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
		item_arr[idx].goal = 0;
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
