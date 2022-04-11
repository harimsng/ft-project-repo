/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:58:33 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 14:22:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CONST_H
# define PHILO_CONST_H

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
