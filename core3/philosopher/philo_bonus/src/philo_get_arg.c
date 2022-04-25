/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_get_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:32:16 by hseong            #+#    #+#             */
/*   Updated: 2022/04/26 03:57:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static t_bool	philo_check_arg(t_arg *arg);

t_bool	philo_get_arg(t_arg *arg, int argc, char **argv)
{
	t_bool	ret;

	if (argc != 5 && argc != 6)
	{
		printf("./philo_bonus  num_philo  num_die  num_eat  \
num_sleep  [num_escape]\n");
		return (FALSE);
	}
	arg->num_philo = ft_atoi(argv[1]);
	arg->num_die = ft_atoi(argv[2]);
	arg->num_eat = ft_atoi(argv[3]);
	arg->num_slp = ft_atoi(argv[4]);
	arg->num_esc = (t_ms)-1;
	if (argc == 6)
		arg->num_esc = ft_atoi(argv[5]);
	ret = philo_check_arg(arg);
	if (ret == FALSE)
		printf("Invalid arguments\n");
	return (ret);
}

t_bool	philo_check_arg(t_arg *arg)
{
	if (arg->num_philo <= 0
		|| arg->num_die <= 0
		|| arg->num_eat <= 0
		|| arg->num_slp <= 0)
		return (FALSE);
	return (TRUE);
}
