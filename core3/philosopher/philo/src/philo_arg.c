/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:55:38 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 08:46:53 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_utils.h"
#include <stdio.h>

static t_bool	arg_check(t_arg *arg);

t_bool	philo_get_arg(int argc, char **argv, t_arg *arg)
{
	t_bool	ret;

	if (argc != 5 && argc != 6)
	{
		printf("invalid arguments.\n./philo  philosophers  time_to_die\
  time_to_eat  time_to_sleep  [time_to_escape]\n");
		return (FALSE);
	}
	arg->num_philo = ft_atou(argv[1]);
	arg->num_die = ft_atou(argv[2]);
	arg->num_eat = ft_atou(argv[3]);
	arg->num_slp = ft_atou(argv[4]);
	arg->num_esc = 0x7FFFFFFFFFFFFFFF;
	if (argc == 6)
		arg->num_esc = ft_atou(argv[5]);
	ret = arg_check(arg);
	if (ret == FALSE)
		printf("invalid argument.\n");
	return (ret);
}

t_bool	arg_check(t_arg *arg)
{
	if (arg->num_philo == 0
		|| arg->num_die == 0
		|| arg->num_eat == 0
		|| arg->num_slp == 0)
		return (FALSE);
	return (TRUE);
}
