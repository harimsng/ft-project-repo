/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:58:33 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 03:40:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CONST_H
# define PHILO_CONST_H

# define INT_MIN (-2147483648LL)

# define MAX_MONITOR (32)
# define PER_MONITOR (20)
# define TIME_SCALE (1)

# define CHILD (1)
# define PARENT (0)

# define TRUE (1)
# define FALSE (0)

# define PHILO_STATES (5)

enum e_state
{
	S_THINK,
	S_LOCK_R,
	S_LOCK_L,
	S_TAKE_EAT,
	S_SLEEP
};

enum e_msg
{
	M_THINK,
	M_TAKE,
	M_EAT,
	M_SLEEP,
	M_DIE
};

#endif
