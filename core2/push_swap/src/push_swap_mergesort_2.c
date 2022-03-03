/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mergesort_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:43 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 00:36:43 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	join_loop(t_deque *a, t_deque *b);
static void		split_deque(t_deque *a, t_deque *b);

t_bool	sort_cycle(t_deque *a, t_deque *b)
{
	while (join_loop(a, b))
		continue ;
	if (b->size == 0 && sort_check(a))
		return (FALSE);
	split_deque(a, b);
	return (TRUE);
}

t_bool	join_loop(t_deque *a, t_deque *b)
{
	size_t		a_head_depth;

	join_edge(a, A_DEQUE);
	join_edge(b, B_DEQUE);
	a->cur = a->head;
	a_head_depth = partial_check(&a->cur, a->size, HEAD, INC);
	a->cur = a->tail;
	a->idx = partial_check(&a->cur, a->size, TAIL, DEC);
	b->cur = b->head;
	b->idx = partial_check(&b->cur, b->size, HEAD, DEC);
	if (b->idx == b->size)
	{
		if (a_head_depth != a->size && a_head_depth > 2 * a->idx)
			join_to_b(a, b, TAIL);
		else if (a_head_depth != a->size && a_head_depth <= 2 * a->idx)
		{
			a->idx = a_head_depth;
			join_to_b(a, b, HEAD);
		}
		else if (b->size != 0)
			join_deques(a, b);
		return (FALSE);
	}
	join_to_a(a, b, HEAD);
	return (TRUE);
}

void	split_deque(t_deque *a, t_deque *b)
{
	size_t	blocks;
	t_node	*node;

	blocks = get_blocks(a, INC);
	blocks = blocks / 2;
	node = a->head;
	while (blocks)
	{
		while (node->item < node->next->item)
		{
			node = node->next;
			pb(a, b);
		}
		node = node->next;
		pb(a, b);
		--blocks;
	}
}

void	join_to_a(t_deque *a, t_deque *b, t_bool pos)
{
	if (pos == TAIL)
		revrot_block(b, B_DEQUE);
	while (a->idx && b->idx)
	{
		if (a->tail->item > b->head->item)
		{
			rra(a, b);
			--a->idx;
		}
		else
		{
			pa(a, b);
			--b->idx;
		}
	}
	while (a->idx--)
		rra(a, b);
	while (b->idx--)
		pa(a, b);
}

void	join_to_b(t_deque *a, t_deque *b, t_bool pos)
{
	if (pos == TAIL)
		revrot_block(a, A_DEQUE);
	while (a->idx && b->idx)
	{
		if (b->tail->item < a->head->item)
		{
			rrb(a, b);
			--b->idx;
		}
		else
		{
			pb(a, b);
			--a->idx;
		}
	}
	while (b->idx--)
		rrb(a, b);
	while (a->idx--)
		pb(a, b);
}
