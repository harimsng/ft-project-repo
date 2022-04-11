/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:42 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 14:24:33 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_utils.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_info	info;
	size_t	detach;

	if (philo_get_arg(argc, argv, &arg) == FALSE)
		return (1);
	if (philo_dinner(&arg, &info) == FALSE)
		return (1);
	detach = philo_watch(&info);
	philo_join(&info, detach);
	philo_mutex_destroy(info.num, &info);
	philo_dealloc(&info);
	return (0);
}
//#include <stdlib.h>
//	system("leaks philo");
