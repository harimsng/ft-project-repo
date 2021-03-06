/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:37 by hseong            #+#    #+#             */
/*   Updated: 2022/04/27 23:20:53 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_state.h"
#include <stdio.h>

static void		philo_finish(t_philo_item *item, int state);

void	*philo_work(void *arg)
{
	t_philo_item	*item;
	int				state;

	item = arg;
	philo_ready(item);
	if (item->id % 2 == 1)
		philo_msleep(item->arg.num_eat / 2);
	state = 0;
	while (state > -1)
	{
		g_philo_state[state++](item);
		state %= PHILO_STATES;
		sem_wait(item->access);
		state -= PHILO_STATES * (item->goal <= 0);
		sem_post(item->access);
	}
	philo_finish(item, (state + 2 * PHILO_STATES - 1) % PHILO_STATES);
	return (NULL);
}

void	philo_finish(t_philo_item *item, int state)
{
	if (state == S_FORK)
	{
		sem_post(item->forks);
		sem_post(item->forks);
	}
}

