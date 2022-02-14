/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/14 23:43:21 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	get_blocks(t_deque *a, t_deque *b);
static size_t	get_depth(t_node *node, t_bool direction);
static void		split_blocks(t_deque *a, t_deque *b);
static void		join_blocks(t_deque *a, t_deque *b, size_t alen, size_t blen);

t_bool	sort_loop(t_deque *a, t_deque *b)
{
	while (get_blocks(a, b))
		continue ;
	if (b->size == 0 && sort_check(a))
		return (FALSE);
	split_blocks(a, b);
	print_data(a, b);
	return (TRUE);
}

// flag == TRUE : from = a, to = b
//      == FALSE: from = b, to = a
t_bool	get_blocks(t_deque *a, t_deque *b)
{
	size_t		a_depth;
	size_t		b_depth;

	a_depth = get_depth(a->tail, 0);
	b_depth = get_depth(b->head, 1);
	if (b_depth == 0)
		return (FALSE);
	join_blocks(a, b, a_depth, b_depth);
	return (TRUE);
}

static size_t	get_depth(t_node *node, t_bool direction)
{
	size_t		depth;

	if (node == NULL)
		return (0);
	depth = 1;
	if (direction == 0)
	{
		while (node->prev != NULL && node->item > node->prev->item)
		{
			node = node->prev;
			++depth;
		}
	}
	else
	{
		while (node->next != NULL && node->item < node->next->item)
		{
			node = node->next;
			++depth;
		}
	}
	return (depth);
}

static void	join_blocks(t_deque *a, t_deque *b, size_t alen, size_t blen)
{
	size_t	len;

	len = alen + blen;
	while (len)
	{
		if (alen && (blen == 0 || a->tail->item > b->head->item))
		{
			rra(a);
			--alen;
		}
		else
		{
			pa(a, b);
			--blen;
		}
		--len;
	}
}

static void		split_blocks(t_deque *a, t_deque *b)
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
