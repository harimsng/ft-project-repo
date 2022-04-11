/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:12 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 14:37:13 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_type.h"
# include "philo_const.h"

t_bool	philo_get_arg(int argc, char **argv, t_arg *arg);

t_bool	philo_dinner(t_arg *arg, t_info *info);
void	philo_state(int state, const t_philo_item *const item);
void	philo_report(int idx, const t_philo_item *const item);

// philo_alloc.c
t_bool	philo_alloc(size_t num, t_info *info);
t_bool	philo_setup(t_arg *arg, t_info *info);
void	philo_dealloc(t_info *info);
void	philo_mutex_destroy(size_t num, t_info *info);

// philo_watch.c
size_t	philo_watch(t_info *info);
void	philo_join(t_info *info, size_t detach);
void	philo_detach(t_info *info);

// philo_time.c
t_ms	philo_get_time(int scale);
void	philo_msleep(t_ms time);
void	philo_ready(const t_philo_item *const item);

// philo_access.c
t_bool	philo_access_recent(t_philo_item *item, t_bool who);

#endif
