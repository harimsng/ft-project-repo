/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mergesort_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 01:13:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	join_loop(t_deque *a, t_deque *b);
static void		split_deque(t_deque *a, t_deque *b);
static void		join_blocks(t_deque *a, t_deque *b, size_t alen, size_t blen);

t_bool	sort_loop(t_deque *a, t_deque *b)
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
	size_t		a_depth;
	size_t		b_depth;

	join_edge(a, TRUE);
	join_edge(b, FALSE);
	a->cur = a->tail;
	b->cur = b->head;
	a_depth = partial_check(&a->cur, a->size, TAIL, DEC);
	b_depth = partial_check(&b->cur, b->size, HEAD, DEC);
	if (b->size == 0)
		return (FALSE);
	join_blocks(a, b, a_depth, b_depth);
	return (TRUE);
}

void	join_blocks(t_deque *a, t_deque *b, size_t alen, size_t blen)
{
	while (alen && blen)
	{
		if (a->tail->item > b->head->item)
		{
			rra(a);
			--alen;
		}
		else
		{
			pa(a, b);
			--blen;
		}
	}
	while (alen--)
		rra(a);
	while (blen--)
		pa(a, b);
}

void		split_deque(t_deque *a, t_deque *b)
{
	size_t	blocks;
	t_node	*node;

	blocks = get_blocks(a, INC);
	blocks = (blocks + 1) / 2;
	node = a->head;
	while (blocks)
	{
		while (node->item < node->next->item)
		{
			node = node->next;
			pb(b, a);
		}
		node = node->next;
		pb(b, a);
		--blocks;
	}
}
/*
void		split_deque(t_deque *a, t_deque *b)
{
	t_node		*head;
	t_node		*tail;

	head = a->head;
	tail = a->tail;
	while (head != tail)
	{
		while (head->item < head->next->item)
		{
			head = head->next;
			pb(b, a);
		}
		head = head->next;
		pb(b, a);
		if (head == tail)
			return ;
		tail = tail->prev;
		while (tail != head && tail->prev->item < tail->item)
			tail = tail->prev;
	}
}
*/
