/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:53:32 by hseong            #+#    #+#             */
/*   Updated: 2022/04/07 10:19:48 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPE_H
# define PHILO_TYPE_H

# include <pthread.h>

typedef pthread_t		t_philo;
typedef pthread_mutex_t	t_fork;
typedef int				t_bool;

typedef struct s_arg
{
	size_t	num_philo;
	size_t	num_die;
	size_t	num_eat;
	size_t	num_slp;
	size_t	num_esc;
}			t_arg;

typedef struct s_pos
{
	size_t	id;
	t_arg	*arg;
	t_fork	*l_fork;
	t_fork	*r_fork;
}			t_pos;

typedef struct s_pack
{
	size_t	num;
	t_philo	*philo_arr;
	t_fork	*fork_arr;
	t_pos	*pos_arr;
}			t_pack;

#endif
