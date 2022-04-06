/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:23:12 by hseong            #+#    #+#             */
/*   Updated: 2022/04/06 22:27:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_type.h"

t_bool	philo_get_arg(int argc, char **argv, t_arg *arg);
void	philo_dinner(t_arg *arg);
void	philo_dealloc(t_pack *pack);

#endif
