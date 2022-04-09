/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:15:40 by hseong            #+#    #+#             */
/*   Updated: 2022/04/09 17:28:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STATE_H
# define PHILO_STATE_H

# include "philo.h"
# include <sys/time.h>

typedef void	(*t_state)(t_philo_item *const);

void	philo_think(t_philo_item *const item);
void	philo_eat(t_philo_item *const item);
void	philo_sleep(t_philo_item *const item);

const static t_state	g_philo_state[3]
= {
	philo_think,
	philo_eat,
	philo_sleep
};

#endif
