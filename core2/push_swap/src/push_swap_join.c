/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:46:21 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 21:50:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_box(t_deque *a, t_deque *b, size_t box)
{
	size_t		box_count;
	size_t		a_depth;
	size_t		b_depth;

	get_depth_tail(a->tail, b->tail, &a_depth, &b_depth);
	join_to(a, b);
	while (a_depth--)
	{
		rra(a);
	}
	join_to(b, a);
	while (b_depth--)
	{
		rra(a);
	}
}

{
	size_t		a_depth;
	size_t		b_depth;
	t_node		*a_top;
	t_node		*b_top;

	a_top = a->head;
	b_top = b->head;
	a_depth = 1;
	while (a_top->next != NULL && a_top->item < a_top->next->item)
	{
		a_top = a_top->next;
		++a_depth;
	}
	b_depth = 1;
	while (b_top->next != NULL && b_top->item > b_top->next->item)
	{
		b_top = b_top->next;
		++b_depth;
	}
	a_top = a->head;
	b_top = b->head;

}
