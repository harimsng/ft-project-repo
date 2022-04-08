/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:12 by hseong            #+#    #+#             */
/*   Updated: 2022/04/08 17:39:59 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_type.h"
# include "philo_const.h"

t_bool	philo_get_arg(int argc, char **argv, t_arg *arg);
void	philo_dinner(t_arg *arg);
void	philo_report(int idx, const t_philo_item *const item);
void	philo_watch(t_info *info);

t_bool	philo_alloc(size_t num, t_info *info);
t_bool	philo_setup(t_arg *arg, t_info *info);
void	philo_dealloc(size_t num, t_info *info);
void	philo_mutex_destroy(size_t num, t_info *info);
void	philo_destroy(size_t num, t_info *info);

t_ms	philo_get_time(void);
void	philo_ready(const t_philo_item * const item);

#endif
