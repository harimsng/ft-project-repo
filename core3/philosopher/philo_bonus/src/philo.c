/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:19:15 by hseong            #+#    #+#             */
/*   Updated: 2022/04/22 05:56:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_arg	arg;
	t_sem	sem_obj;

	info.arg = &arg;
	info.sem_obj = &sem_obj;
	if (philo_get_arg(info.arg, argc, argv) == FALSE)
		return (1);
	if (philo_allocate(&info) == FALSE)
		return (1);
	if (philo_dinner(&info) == FALSE)
		return (1);
	if (philo_wait(&info) == FALSE)
		return (1);
	philo_deallocate(&info);
	return (0);
}
