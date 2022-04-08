/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_watch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:59:56 by hseong            #+#    #+#             */
/*   Updated: 2022/04/08 17:05:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_watch(t_info *info)
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
