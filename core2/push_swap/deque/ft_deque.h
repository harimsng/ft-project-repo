/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:45:23 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:29:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include "dlinkedlist.h"

typedef t_dlist	t_deque;

// sa, sb, ss
void	inst_swap(t_deque *deque);
void	inst_swap_two(t_deque *first, t_deque *second);

// pa, pb
int		inst_push(t_deque *to, t_deque *from);

// ra, rb, rr
void	inst_rotation(t_deque *deque);
void	inst_rotation_two(t_deque *first, t_deque *second);

// rra, rrb, rrr
void	inst_revrot(t_deque *deque);
void	inst_revrot_two(t_deque *first, t_deque *second);

#endif
