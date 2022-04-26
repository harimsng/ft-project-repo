/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:19:15 by hseong            #+#    #+#             */
/*   Updated: 2022/04/26 05:32:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	info;
	t_arg	arg;
	int		ret;

	info.arg = &arg;
	if (philo_get_arg(info.arg, argc, argv) == FALSE)
		return (1);
	if (philo_allocate(&info) == FALSE)
		return (1);
	ret = philo_dinner(&info);
	if (ret != 0)
		return (ret - 1);
	if (philo_wait(&info) == FALSE)
		return (1);
	philo_deallocate(&info);
	return (0);
}
