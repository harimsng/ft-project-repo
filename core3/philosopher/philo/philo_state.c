/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/04/07 21:40:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <unistd.h>

void	philo_eating(suseconds_t duration)
{
	usleep(duration * 1000);
}

void	philo_sleeping(suseconds_t duration)
{
	usleep(duration * 1000);
}

void	philo_thinking(suseconds_t duration)
{
	usleep(duration * 1000);
}

t_bool	philo_isdie(suseconds_t diff, suseconds_t num_die)
{
	t_time	time;

	gettimeofday(&time, NULL);
	if (time.tv_usec - diff > num_die)
		return (TRUE);
	return (FALSE);
}
