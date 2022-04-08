/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/04/08 17:32:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <unistd.h>

void	philo_eating(t_philo_item *item)
{
	usleep(item->arg.num_eat * 1000);
}

void	philo_sleeping(t_philo_item *item)
{
	usleep(item->arg.num_slp * 1000);
}

t_bool	philo_isdie(suseconds_t diff, suseconds_t num_die)
{
	t_time	time;

	gettimeofday(&time, NULL);
	if (time.tv_usec - diff > num_die)
		return (TRUE);
	return (FALSE);
}
