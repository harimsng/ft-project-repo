/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:22:02 by hseong            #+#    #+#             */
/*   Updated: 2022/04/26 05:35:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	philo_dinner(t_info *info)
{
	size_t			idx;
	pid_t			philo;
	t_philo_item	*item_arr;
	t_ms			init_time;

	idx = 0;
	item_arr = info->item_arr;
	init_time = philo_get_time() + 500 + info->arg->num_philo * 5;
	while (idx < info->arg->num_philo)
	{
		philo = fork();
		*item_arr = (t_philo_item){idx + 1, *info->arg,
			init_time, info->arg->num_esc, init_time, NULL, NULL, NULL};
		if (philo == 0)
			return (philo_create(item_arr) + 1);
		else if (philo == -1)
		{
			printf("process creation failed\n");
			return (1);
		}
		++item_arr;
		info->philo_arr[idx] = philo;
		++idx;
	}
	return (0);
}
