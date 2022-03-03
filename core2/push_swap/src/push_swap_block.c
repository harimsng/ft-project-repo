/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:17:56 by hseong            #+#    #+#             */
/*   Updated: 2022/03/03 23:24:41 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_block(t_deque *deque, t_bool which)
{
	size_t		depth;

	deque->cur = deque->head;
	depth = partial_check(&deque->cur, deque->size, HEAD, which);
	if (which == TRUE)
		while (depth--)
			ra(deque, deque);
	else
		while (depth--)
			rb(deque, deque);
}

void	revrot_block(t_deque *deque, t_bool which)
{
	size_t		depth;

	deque->cur = deque->tail;
	depth = partial_check(&deque->cur, deque->size, TAIL, !which);
	if (which == TRUE)
		while (depth--)
			rra(deque, deque);
	else
		while (depth--)
			rrb(deque, deque);
}
