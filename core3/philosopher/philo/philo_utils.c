/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:32:55 by hseong            #+#    #+#             */
/*   Updated: 2022/04/06 22:14:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_type.h"
#include <pthread.h>
#include <stdlib.h>

void	philo_dealloc(t_pack *pack)
{
	size_t		idx;

	idx = 0;
	while (idx < pack->num)
	{
		if (pack->philo_arr != NULL)
			free(pack->philo_arr + idx);
		if (pack->fork_arr != NULL)
			free(pack->fork_arr + idx);
		if (pack->pos_arr != NULL)
			free(pack->pos_arr + idx);
		++idx;
	}
}
