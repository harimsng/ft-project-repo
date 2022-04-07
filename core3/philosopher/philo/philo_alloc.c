/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:23:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/07 21:34:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

t_bool	philo_alloc(size_t num, t_info *info)
{
	t_philo			*philo_arr;
	t_fork			*fork_arr;
	t_philo_item	*item_arr;

	philo_arr = malloc(sizeof(t_philo) * num);
	fork_arr = malloc(sizeof(t_fork) * num);
	item_arr = malloc(sizeof(t_philo_item) * num);
	if (philo_arr == NULL || fork_arr == NULL
			|| item_arr == NULL)
	{
		printf("memory allocation failed.\n");
		philo_dealloc(num, info);
		return (FALSE);
	}
	info->philo_arr = philo_arr;
	info->fork_arr = fork_arr;
	info->item_arr = item_arr;
	return (TRUE);
}

t_bool	philo_setup(t_arg *arg, t_info *info)
{
	size_t		idx;

	idx = 0;
	while (idx < info->num)
	{
		if (pthread_mutex_init(info->fork_arr + idx, NULL) != 0)
		{
			philo_mutex_destroy(idx, info);
			philo_dealloc(arg->num_philo, info);
			return (FALSE);
		}
		++idx;
	}
	idx = 0;
	while (idx < info->num)
	{
		info->item_arr[idx] = (t_philo_item){idx + 1, 0, arg,
		info->fork_arr + idx, info->fork_arr + ((idx + 1) % info->num)};
		++idx;
	}
	return (TRUE);
}

void	philo_dealloc(size_t num, t_info *info)
{
	size_t		idx;

	idx = 0;
	while (idx < num)
	{
		if (info->philo_arr != NULL)
			free(info->philo_arr + idx);
		if (info->fork_arr != NULL)
			free(info->fork_arr + idx);
		if (info->item_arr != NULL)
			free(info->item_arr + idx);
		++idx;
	}
}

void	philo_mutex_destroy(size_t num, t_info *info)
{
	size_t	idx;

	printf("mutex initialization failed.\n");
	idx = 0;
	while (idx < num)
	{
		pthread_mutex_destroy(info->fork_arr + idx);
		++idx;
	}
}

void	philo_destroy(size_t num, t_info *info)
{
	size_t		idx;

	philo_mutex_destroy(info->num, info);
	philo_dealloc(info->num, info);
	idx = 0;
	while (idx < num)
	{
		pthread_detach(info->philo_arr[idx]);
		++idx;
	}
}
