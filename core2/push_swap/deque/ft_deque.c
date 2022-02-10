/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:01:33 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 17:02:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	inst_swap(t_deque *deque)
{
	t_item	up;
	t_item	down;	

	if (deque->size <= 1)
		return ;
	up = pop_front(deque, delete_item);
	down = pop_front(deque, delete_item);
	push_front(deque, up);
	push_front(deque, down);
}

int	inst_push(t_deque *to, t_deque *from)
{
	if (from->size == 0)
		return (0);
	push_front(to, pop_front(from, delete_item));
	return (1);
}

void	inst_rotation(t_deque *deque)
{
	if (deque->size <= 1)
		return ;
	push_back(deque, pop_front(deque, delete_item));
}

void	inst_revrot(t_deque *deque)
{
	if (deque->size <= 1)
		return ;
	push_front(deque, pop_back(deque, delete_item));
}
