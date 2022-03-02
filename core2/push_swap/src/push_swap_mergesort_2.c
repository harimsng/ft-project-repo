/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mergesort_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:38:43 by hseong            #+#    #+#             */
/*   Updated: 2022/03/01 23:37:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	join_loop(t_deque *deques[2]);
static void		split_deque(t_deque *deques[2]);
static void		join_blocks(t_deque *deques[2], size_t alen, size_t blen);

t_bool	sort_loop(t_deque *deques[2])
{
	while (join_loop(deques))
		continue ;
	if ((deques[1])->size == 0 && sort_check(deques[0]))
		return (FALSE);
	split_deque(deques);
	return (TRUE);
}

t_bool	join_loop(t_deque *deques[2])
{
	size_t		a_depth;
	size_t		b_depth;
	t_deque		*a;
	t_deque		*b;

	a = deques[0];
	b = deques[1];
	join_edge(a, TRUE);
	join_edge(b, FALSE);
	a->cur = a->tail;
	b->cur = b->head;
	a_depth = partial_check(&a->cur, a->size, TAIL, DEC);
	b_depth = partial_check(&b->cur, b->size, HEAD, DEC);
	if (b->size == 0)
		return (FALSE);
	join_blocks(deques, a_depth, b_depth);
	return (TRUE);
}

void	join_blocks(t_deque *deques[2], size_t alen, size_t blen)
{
	t_deque	*a;
	t_deque	*b;

	a = deques[0];
	b = deques[1];
	while (alen && blen)
	{
		if (a->tail->item > b->head->item)
		{
			rra(deques);
			--alen;
		}
		else
		{
			pa(deques);
			--blen;
		}
	}
	while (alen--)
		rra(deques);
	while (blen--)
		pa(deques);
}

void	split_deque(t_deque *deques[2])
{
	size_t	blocks;
	t_node	*node;

	blocks = get_blocks(deques[0], INC);
	blocks = (blocks + 1) / 2;
	node = (deques[0])->head;
	while (blocks)
	{
		while (node->item < node->next->item)
		{
			node = node->next;
			pb(deques);
		}
		node = node->next;
		pb(deques);
		--blocks;
	}
}
