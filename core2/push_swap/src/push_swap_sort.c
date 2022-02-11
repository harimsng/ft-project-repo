/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/11 21:49:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_depth_head(t_node *head);
static size_t	get_depth_tail(t_node *tail);
static void		split_blocks(t_deque *a, t_deque *b);
static t_bool	join_block(t_deque *a, t_deque *b);

t_bool	sort_blocks(t_deque *a, t_deque *b)
{
	while (join_block(a, b))
		continue ;
	if (b->size == 0 && sort_check(a))
		return (FALSE);
	split_blocks(a, b);
	return (TRUE);
}

// flag == TRUE : from = a, to = b
//      == FALSE: from = b, to = a
t_bool	join_block(t_deque *a, t_deque *b)
{
	t_deque		*temp;
	size_t		a_depth;
	size_t		b_depth;

	get_depth_tail(a->tail, &a_depth);
	get_depth_head(b->tail, &b_depth);
	if (b_depth == 0)
		return (FALSE);
	while (from_depth)
	{
		rra(a);
		--from_depth;
	}
	while (to_depth)
	{
		rra(a);
		--to_depth;
	}
	return (TRUE);
}
