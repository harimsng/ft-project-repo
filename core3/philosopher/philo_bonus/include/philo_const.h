/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:21:03 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 13:10:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CONST_H
# define PHILO_CONST_H

# define TRUE (1)
# define FALSE (0)

static const char	*g_sem_name = "philo_forks";
static const char	*g_sem_speak = "philo_speak";

enum e_message
{
	M_THINK,
	M_TAKE,
	M_EAT,
	M_SLEEP,
	M_DIE
};

# define PHILO_STATES (5)

enum e_state
{
	S_THINK,
	S_R_FORK,
	S_L_FORK,
	S_EAT,
	S_SLEEP
};

#endif
