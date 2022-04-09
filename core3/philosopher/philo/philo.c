/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:42 by hseong            #+#    #+#             */
/*   Updated: 2022/04/09 22:07:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_utils.h"
# include <stdio.h>

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_info	info;

	if (philo_get_arg(argc, argv, &arg) == FALSE)
		return (1);
	if (philo_dinner(&arg, &info) == FALSE)
		return (1);
	philo_watch(&arg, &info);
	printf("watch ends\n");
	philo_join(&info);
	printf("joined\n");
	philo_destroy(info.num, &info);
	printf("destroyed\n");
	return (0);
}
