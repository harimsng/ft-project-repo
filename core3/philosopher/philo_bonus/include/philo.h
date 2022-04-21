/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:19:52 by hseong            #+#    #+#             */
/*   Updated: 2022/04/22 05:41:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_type.h"
# include "philo_const.h"

t_bool			philo_get_arg(t_arg *arg, int argc, char **argv);
t_bool			philo_dinner(t_info *info);
void			philo_work(t_philo_item *item);
void			philo_report(int msg, t_philo_item *item);
t_bool			philo_wait(t_info *info);

void			philo_terminate(t_info *info, size_t except, size_t len);
t_bool			philo_allocate(t_info *info);
void			philo_deallocate(t_info *info);

t_ms			philo_get_time(void);
void			philo_msleep(t_ms ms);
void			philo_ready(t_philo_item *item);

// utils
unsigned int	ft_atou(const char *s);

#endif
