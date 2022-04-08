/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:48:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/08 10:09:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static const char	*g_report[]
= {
	"taken a fork",
	"is eating",
	"is sleeping",
	"is thinking",
	"died",
};

int	philo_report(int idx, size_t num, t_ms t0)
{
	static t_fork	speak;
	static t_bool	init;

	if (init == FALSE)
	{
		pthread_mutex_init(&speak, NULL);
		init = TRUE;
	}
	pthread_mutex_lock(&speak);
	printf("%9lld	%zu %s\n", philo_get_time() - t0, num, g_report[idx]);
	pthread_mutex_unlock(&speak);
	return (0);
}
