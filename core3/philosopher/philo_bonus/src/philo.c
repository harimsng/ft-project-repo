/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:19:15 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 08:49:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_arg	arg;

	info.arg = &arg;
	if (philo_get_arg(&arg, argc, argv) == FALSE)
		return (1);
	if (philo_allocate(&info) == FALSE)
		return (1);
	if (philo_dinner(&info) == FALSE)
		return (1);
	philo_watch(&info);
	return (0);
}
