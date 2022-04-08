/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:52:35 by hseong            #+#    #+#             */
/*   Updated: 2022/04/08 17:15:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	philo_get_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 100000 + time.tv_usec / 10);
}

void	philo_ready(const t_philo_item * const item)
{
	t_ms	time;
	t_ms	start_time;

	start_time = item->init_time;
	time = philo_get_time();
	while (time < start_time)
		time = philo_get_time();
}
