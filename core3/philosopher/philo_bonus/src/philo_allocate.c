/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_allocate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:50:15 by hseong            #+#    #+#             */
/*   Updated: 2022/04/22 05:10:41 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static t_bool	philo_sem_open(t_info *info);
static void		philo_sem_unlink(t_info *info);

t_bool	philo_allocate(t_info *info)
{
	info->num = info->arg->num_philo;
	if (philo_sem_open(info) == FALSE)
	{
		printf("semaphore creation failed.\n");
		return (FALSE);
	}
	info->philo_arr = malloc(sizeof(t_philo) * info->num);
	info->item_arr = malloc(sizeof(t_philo_item) * info->num);
	info->thread_arr = malloc(sizeof(t_thread) * info->num);
	info->monitor_arr = malloc(sizeof(t_monitor) * info->num);
	if (info->philo_arr == NULL
		|| info->item_arr == NULL
		|| info->thread_arr == NULL
		|| info->monitor_arr == NULL)
	{
		philo_deallocate(info);
		printf("memory allocation failed.\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	philo_sem_open(t_info *info)
{
	t_sem	*sem_obj;

	sem_obj = info->sem_obj;
	sem_obj->forks = sem_open(g_sem_forks, O_CREAT, 0666, info->num);
	sem_obj->speak = sem_open(g_sem_speak, O_CREAT, 0666, 1);
	sem_obj->access = sem_open(g_sem_access, O_CREAT, 0666, 1);
	sem_obj->wait = sem_open(g_sem_wait, O_CREAT, 0666, 1);
	if (sem_obj->forks == SEM_FAILED
		|| sem_obj->speak == SEM_FAILED
		|| sem_obj->access == SEM_FAILED
		|| sem_obj->wait == SEM_FAILED)
	{
		philo_sem_unlink(info);
		return (FALSE);
	}
	return (TRUE);
}

void	philo_deallocate(t_info *info)
{
	philo_sem_unlink(info);
	if (info->philo_arr != NULL)
		free(info->philo_arr);
	if (info->item_arr != NULL)
		free(info->item_arr);
	if (info->thread_arr != NULL)
		free(info->thread_arr);
	if (info->monitor_arr != NULL)
		free(info->monitor_arr);
}

void	philo_terminate(t_info *info, size_t except, size_t len)
{
	size_t			idx;

	idx = 0;
	while (idx < len)
	{
		if (idx == except)
		{
			++idx;
			continue ;
		}
		kill(info->philo_arr[idx], SIGINT);
		++idx;
	}
}

void	philo_sem_unlink(t_info *info)
{
	sem_close(info->sem_obj->forks);
	sem_close(info->sem_obj->speak);
	sem_close(info->sem_obj->access);
	sem_close(info->sem_obj->wait);
	sem_unlink(g_sem_forks);
	sem_unlink(g_sem_speak);
	sem_unlink(g_sem_access);
	sem_unlink(g_sem_wait);
}
