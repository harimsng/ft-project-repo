/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:02:07 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:26:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	inst_swap(t_deque *deque)
{
	t_item	up;
	t_item	down;	

	if (deque->size <= 1)
		return ;
	up = pop_front(deque);
	down = pop_front(deque);
	push_front(deque, up);
	push_front(deque, down);
}

void	inst_swap_two(t_deque *first, t_deque *second)
{
	inst_swap(first);
	inst_swap(second);
}
