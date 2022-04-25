/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:14:43 by hseong            #+#    #+#             */
/*   Updated: 2022/04/25 23:22:45 by hseong           ###   ########.fr       */
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
		printf("%zu print access wait\n", item->id);
		sem_wait(item->access);
		printf("%zu print access acquired\n", item->id);
		if (item->goal <= 0)
		{
			sem_post(item->access);
			return ;
		}
		printf("%zu speak wait\n", item->id);
		sem_wait(item->speak);
		printf("%zu speak acquired\n", item->id);
	}
	sem_post(item->access);
	printf("%zu print access post\n", item->id);
	printf("%6lld %5zu %s\n", philo_get_time() - item->init_time,
		item->id, g_state_message[msg]);
	if (msg != M_DIE)
		sem_post(item->speak);
	printf("%zu speak post\n", item->id);
}
