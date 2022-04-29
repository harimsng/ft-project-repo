/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_allocate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:50:15 by hseong            #+#    #+#             */
/*   Updated: 2022/04/29 20:24:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static t_bool	philo_sem_open(t_info *info);
static void		philo_unlink(void);

static const char	*g_sem_forks = "/philo_sem_forks";
static const char	*g_sem_speak = "/philo_sem_speak";
static const char	*g_sem_access = "/philo_sem_access";
static const char	*g_sem_wait = "/philo_sem_monitor";

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
	t_fork	*sem_obj[4];

	philo_unlink();
	sem_obj[0] = sem_open(g_sem_forks, O_CREAT | O_EXCL, 0777, info->num);
	sem_obj[1] = sem_open(g_sem_speak, O_CREAT | O_EXCL, 0777, 1);
	sem_obj[2] = sem_open(g_sem_access, O_CREAT | O_EXCL, 0777, 1);
	sem_obj[3] = sem_open(g_sem_wait, O_CREAT | O_EXCL, 0777, 1);
	if (sem_obj[0] == SEM_FAILED
		|| sem_obj[1] == SEM_FAILED
		|| sem_obj[2] == SEM_FAILED
		|| sem_obj[3] == SEM_FAILED)
	{
		philo_unlink();
		return (FALSE);
	}
	sem_close(sem_obj[0]);
	sem_close(sem_obj[1]);
	sem_close(sem_obj[2]);
	sem_close(sem_obj[3]);
	return (TRUE);
}

void	philo_deallocate(t_info *info)
{
	philo_unlink();
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

void	philo_unlink(void)
{
	sem_unlink(g_sem_forks);
	sem_unlink(g_sem_speak);
	sem_unlink(g_sem_access);
	sem_unlink(g_sem_wait);
}
