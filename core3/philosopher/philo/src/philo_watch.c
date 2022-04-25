/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:06:20 by hseong            #+#    #+#             */
/*   Updated: 2022/04/26 04:10:14 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

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
			if (philo_access_parent(item_arr + idx) == FALSE)
			{
				philo_stop(info);
				philo_report(M_DIE, item_arr + idx);
				return ;
			}
			++idx;
		}
		if (philo_goal_check(info) == TRUE)
			return ;
		usleep(100);
	}
}

// dead thread is not terminated by pthread_detach()
// when the main process have parent(ex. debbuger)
void	philo_join(t_info *info)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = info->num;
	if (info->num == 1)
	{
		pthread_detach(info->philo_arr[idx]);
		return ;
	}
	while (idx < len)
	{
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
