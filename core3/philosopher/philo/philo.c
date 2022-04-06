/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:42 by hseong            #+#    #+#             */
/*   Updated: 2022/04/06 22:33:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_type.h"
#include "philo_const.h"
#include "philo_utils.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;

	if (philo_get_arg(argc, argv, &arg) == FALSE)
		return (1);
	philo_dinner(&arg);
	return (0);
}
