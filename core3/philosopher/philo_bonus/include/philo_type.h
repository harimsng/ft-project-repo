/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:06:46 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 13:37:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPE_H
# define PHILO_TYPE_H

# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>

typedef unsigned long long int	t_uint64;
typedef long long int			t_int64;
typedef pthread_t				t_thread;
typedef sem_t					t_fork;
typedef t_uint64				t_ms;
typedef int						t_bool;
typedef pid_t					t_philo;

typedef struct s_arg
{
	t_uint64	num_philo;
	t_ms		num_die;
	t_ms		num_eat;
	t_ms		num_slp;
	t_ms		num_esc;
}				t_arg;

typedef struct s_philo_item
{
	size_t		id;
	t_arg		arg;
	t_ms		init_time;
	t_ms		goal;
	t_ms		recent;
	t_fork		*forks;
	t_fork		*speak;
	t_fork		*access;
}				t_philo_item;

typedef struct s_info
{
	t_arg			*arg;
	t_fork			*forks;	
	t_fork			*speak;
	t_philo			*philo_arr;
	t_philo_item	*item_arr;
}				t_info;

#endif
