/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:14:43 by hseong            #+#    #+#             */
/*   Updated: 2022/04/27 19:15:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static const char	*g_state_message[5] = {
	"is thinking",
	"taken a fork",
	"is eating",
	"is sleeping",
	"died"
};

void	philo_report(int msg, t_philo_item *item)
{
	if (msg != M_DIE)
	{
		sem_wait(item->speak);
		sem_wait(item->access);
		if (item->goal <= 0)
		{
			sem_post(item->access);
			sem_post(item->speak);
			return ;
		}
		sem_post(item->access);
	}
	printf("%6lld %5zu %s\n", philo_get_time() - item->init_time,
		item->id, g_state_message[msg]);
	if (msg != M_DIE)
		sem_post(item->speak);
}
