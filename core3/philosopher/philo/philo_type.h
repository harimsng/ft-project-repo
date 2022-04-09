/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:53:32 by hseong            #+#    #+#             */
/*   Updated: 2022/04/09 21:52:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPE_H
# define PHILO_TYPE_H

# include <pthread.h>
# include <sys/time.h>

typedef pthread_t				t_philo;
typedef pthread_mutex_t			t_fork;
typedef struct timeval			t_time;
typedef int						t_bool;
typedef unsigned long long int	t_ms;

typedef struct s_arg
{
	size_t	num_philo;
	t_ms	num_die;
	t_ms	num_eat;
	t_ms	num_slp;
	t_ms	num_esc;
}			t_arg;

typedef struct s_philo_item
{
	size_t		id;
	t_ms		init_time;
	t_ms		recent;
	long int	goal;
	t_arg		*arg;
	t_fork		*l_fork;
	t_fork		*r_fork;
}			t_philo_item;

typedef struct s_info
{
	size_t			num;
	t_philo			*philo_arr;
	t_fork			*fork_arr;
	t_philo_item	*item_arr;
}			t_info;

#endif
