/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:21:03 by hseong            #+#    #+#             */
/*   Updated: 2022/04/22 01:36:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_CONST_H
# define PHILO_CONST_H

# define TRUE (1)
# define FALSE (0)

static const char	*g_sem_forks = "philo_forks";
static const char	*g_sem_speak = "philo_speak";
static const char	*g_sem_access = "philo_access";
static const char	*g_sem_wait = "philo_monitor";

enum e_message
{
	M_THINK,
	M_TAKE,
	M_EAT,
	M_SLEEP,
	M_DIE
};

# define PHILO_STATES (4)

enum e_state
{
	S_THINK,
	S_FORK,
	S_EAT,
	S_SLEEP
};

#endif
