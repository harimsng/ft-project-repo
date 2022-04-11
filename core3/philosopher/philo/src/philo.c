/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:42 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 14:14:41 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_utils.h"
# include <stdio.h>
# include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_info	info;
	size_t	detach;

	if (philo_get_arg(argc, argv, &arg) == FALSE)
		return (1);
	printf("got arguments\n");
	if (philo_dinner(&arg, &info) == FALSE)
		return (1);
	printf("watch starts\n");
	detach = philo_watch(&info);
	printf("watch ends\n");
	philo_join(&info, detach);
	printf("threads joined\n");
	philo_mutex_destroy(info.num, &info);
	philo_dealloc(&info);
	printf("deallocated\n");
	return (0);
}
//	system("leaks philo");
