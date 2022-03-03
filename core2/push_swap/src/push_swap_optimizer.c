/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_optimizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:13:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 01:03:21 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HEAD = 1, TAIL = 0
// INC = 1, DEC = 0
// which TRUE = a, FALSE = b
// this function merge top and bottom block if conditions met.
// ex) 4 5 6 ... 1 2 3 >> 1 2 3 4 5 6 ...
void	join_edge(t_deque *deque, t_bool which)
{
	if (which == TRUE)
	{
		while (deque->head->item > deque->tail->item)
			rra(deque, deque);
	}
	else if (deque->size > 1)
	{
		while (deque->head->item < deque->tail->item)
			rrb(deque, deque);
	}
}

void	join_deques(t_deque *a, t_deque *b)
{
	size_t		count;

	a->cur = a->head;
	count = 1;
	while (count < a->size && b->head->item > a->cur->item)
	{
		a->cur = a->cur->next;
		++count;
	}
	a->idx = a->size;
	if (count <= a->size / 2)
	{
		a->idx = count;
		while (count)
		{
			ra(a, b);
			--count;
		}
	}
	join_to_a(a, b, HEAD);
}
