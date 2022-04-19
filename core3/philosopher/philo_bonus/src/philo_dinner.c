/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:22:02 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 13:37:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_dinner(t_info *info)
{
	size_t			idx;
	size_t			len;
	pid_t			philo;
	t_philo_item	*item_arr;
	t_ms			init_time;

	idx = 0;
	len = info->arg->num_philo;
	item_arr = info->item_arr;
	init_time = philo_get_time() + info->arg->num_philo;
	while (idx < len)
	{
		philo = fork();
		*item_arr = (t_philo_item){idx + 1, *info->arg,
			init_time, info->arg->num_esc, 0, info->forks, info->speak, NULL};
		if (philo == 0)
		{
			philo_work(item_arr);
			return (FALSE);
		}
		info->philo_arr[idx] = philo;
		++idx;
	}
	return (TRUE);
}
