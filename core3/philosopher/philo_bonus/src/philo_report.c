/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:14:43 by hseong            #+#    #+#             */
/*   Updated: 2022/04/22 06:25:57 by hseong           ###   ########.fr       */
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
		printf("report %d\n", msg);
		sem_wait(item->speak);
		printf("report1\n");
		if (item->goal <= 0)
		{
			sem_post(item->speak);
			return ;
		}
		printf("report2\n");
	}
	printf("%6lld %5zu %s\n", philo_get_time() - item->init_time,
		item->id, g_state_message[msg]);
	if (msg != M_DIE)
		sem_post(item->speak);
}
