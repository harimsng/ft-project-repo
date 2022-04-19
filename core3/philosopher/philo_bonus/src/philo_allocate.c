/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_allocate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:50:15 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 11:19:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

t_bool	philo_allocate(t_info *info)
{
	info->forks = sem_open(g_sem_name, O_CREAT, 0666, info->arg->num_philo);
	info->speak = sem_open(g_sem_speak, O_CREAT, 06666, 1);
	if (info->forks == SEM_FAILED || info->speak == SEM_FAILED)
	{
		if (info->forks != SEM_FAILED)
			sem_close(info->forks);
		printf("semaphore creation failed.\n");
		return (FALSE);
	}
	info->philo_arr = malloc(sizeof(t_philo) * info->arg->num_philo);
	info->item_arr = malloc(sizeof(t_philo_item) * info->arg->num_philo);
	if (info->philo_arr == NULL || info->item_arr == NULL)
	{
		philo_deallocate(info);
		return (FALSE);
	}
	return (TRUE);
}

void	philo_deallocate(t_info *info)
{
	sem_close(info->forks);
	sem_close(info->speak);
	if (info->philo_arr != NULL)
		free(info->philo_arr);
	if (info->item_arr != NULL)
		free(info->item_arr);
}
