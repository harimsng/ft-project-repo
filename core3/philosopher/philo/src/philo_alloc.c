/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:23:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/26 04:10:40 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

static t_bool	philo_mutex_init(t_info *info);

t_bool	philo_alloc(size_t num, t_info *info)
{
	t_philo			*philo_arr;
	t_fork			*fork_arr;
	t_philo_item	*item_arr;
	t_fork			*access_arr;

	philo_arr = malloc(sizeof(t_philo) * num);
	fork_arr = malloc(sizeof(t_fork) * num);
	item_arr = malloc(sizeof(t_philo_item) * num);
	access_arr = malloc(sizeof(t_fork) * num);
	if (philo_arr == NULL || fork_arr == NULL
		|| item_arr == NULL || access_arr == NULL)
	{
		printf("memory allocation failed.\n");
		philo_dealloc(info);
		return (FALSE);
	}
	info->philo_arr = philo_arr;
	info->fork_arr = fork_arr;
	info->item_arr = item_arr;
	info->access_arr = access_arr;
	pthread_mutex_init(info->speak, NULL);
	return (TRUE);
}

t_bool	philo_setup(t_arg *arg, t_info *info)
{
	size_t		idx;

	if (philo_mutex_init(info) == FALSE)
		return (FALSE);
	idx = 0;
	while (idx < info->num)
	{
		info->item_arr[idx] = (t_philo_item){idx + 1, 0, 0, arg->num_esc, *arg,
			info->fork_arr + idx, info->fork_arr + ((idx + 1) % info->num),
			info->access_arr + idx, info->speak};
		++idx;
	}
	return (TRUE);
}

void	philo_dealloc(t_info *info)
{
	if (info->philo_arr != NULL)
		free(info->philo_arr);
	if (info->fork_arr != NULL)
		free(info->fork_arr);
	if (info->item_arr != NULL)
		free(info->item_arr);
	if (info->access_arr != NULL)
		free(info->access_arr);
}

void	philo_mutex_destroy(size_t num, t_info *info)
{
	size_t	idx;

	idx = 0;
	while (idx < num)
	{
		pthread_mutex_destroy(info->fork_arr + idx);
		pthread_mutex_destroy(info->access_arr + idx);
		++idx;
	}
	pthread_mutex_destroy(info->item_arr->speak);
}

t_bool	philo_mutex_init(t_info *info)
{
	size_t	idx;
	int		ret1;
	int		ret2;

	idx = 0;
	while (idx < info->num)
	{
		ret1 = pthread_mutex_init(info->fork_arr + idx, NULL) != 0;
		ret2 = pthread_mutex_init(info->access_arr + idx, NULL) != 0;
		if (ret1 != 0 || ret2 != 0)
		{
			if (ret1 != 0)
				pthread_mutex_destroy(info->fork_arr + idx);
			printf("mutex initialization failed.\n");
			philo_mutex_destroy(idx, info);
			philo_dealloc(info);
			return (FALSE);
		}
		++idx;
	}
	return (TRUE);
}
