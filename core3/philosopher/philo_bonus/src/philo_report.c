/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:14:43 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 12:15:02 by hseong           ###   ########.fr       */
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
	sem_wait(item->speak);

	printf("%6lld %5zu %s\n", philo_get_time() - item->init_time,
		item->id, g_state_message[msg]);
	sem_post(item->speak);
}
