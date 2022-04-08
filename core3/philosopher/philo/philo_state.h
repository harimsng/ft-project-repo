/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:15:40 by hseong            #+#    #+#             */
/*   Updated: 2022/04/08 17:32:43 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STATE_H
# define PHILO_STATE_H

# include "philo.h"
# include <sys/time.h>

void	philo_eating(t_philo_item *item);
void	philo_sleeping(t_philo_item *item);
t_bool	philo_isdie(suseconds_t diff, suseconds_t num_die);

#endif
