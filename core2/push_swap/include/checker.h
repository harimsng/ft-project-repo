/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:28:09 by hseong            #+#    #+#             */
/*   Updated: 2022/03/01 00:34:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define ERROR_BIT (0b10)
# define KO_BIT (0b1)
# define OK_BIT (0b0)

char	*get_next_line(int fd);
t_bool	check_inst(t_deque *a_deque, t_deque *b_deque);

#endif
