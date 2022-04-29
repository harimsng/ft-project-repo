/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:42:27 by hseong            #+#    #+#             */
/*   Updated: 2022/04/27 17:45:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_exit(t_philo_item *item)
{
//	sem_post(item->finished);
	sem_close(item->speak);
	sem_close(item->access);
	sem_close(item->forks);
//	sem_wait(item->terminate);
}
