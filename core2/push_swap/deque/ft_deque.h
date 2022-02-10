/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:45:23 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 19:50:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include "dlinkedlist.h"
# include "ft_utils.h"

typedef t_dlist	t_deque;

// basis instruction
void	inst_swap(t_deque *deque);
int		inst_push(t_deque *to, t_deque *from);
void	inst_rotation(t_deque *deque);
void	inst_revrot(t_deque *deque);

// functions depend on t_item
void	print_item(t_item item);
void	delete_item(t_item item);

#endif
