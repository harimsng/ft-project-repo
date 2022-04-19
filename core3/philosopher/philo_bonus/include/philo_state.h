/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:06:51 by hseong            #+#    #+#             */
/*   Updated: 2022/04/19 13:08:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STATE_H
# define PHILO_STATE_H

# include "philo_type.h"

void	philo_think(t_philo_item *item);
void	philo_fork(t_philo_item *item);
void	philo_eat(t_philo_item *item);
void	philo_sleep(t_philo_item *item);

typedef void	(*t_state_func)(t_philo_item *);

static const t_state_func	g_philo_state[PHILO_STATES] = {
	philo_think,
	philo_fork,
	philo_eat,
	philo_sleep
};

#endif
