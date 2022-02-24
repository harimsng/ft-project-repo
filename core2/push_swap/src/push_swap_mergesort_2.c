/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mergesort_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/24 11:22:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	get_blocks(t_deque *a, t_deque *b);
static void		split_blocks(t_deque *a, t_deque *b);
static void		join_blocks(t_deque *a, t_deque *b, size_t alen, size_t blen);

t_bool	sort_loop(t_deque *a, t_deque *b)
{
	while (get_blocks(a, b))
		continue ;
	if (b->size == 0 && sort_check(a))
		return (FALSE);
	split_blocks(a, b);
	return (TRUE);
}

t_bool	get_blocks(t_deque *a, t_deque *b)
{
	size_t		a_depth;
	size_t		b_depth;

	a_depth = get_depth_des(a->tail, 0);
	b_depth = get_depth_des(b->head, 1);
	if (b_depth == 0 || b_depth == b->size)
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

void		split_blocks(t_deque *a, t_deque *b)
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
