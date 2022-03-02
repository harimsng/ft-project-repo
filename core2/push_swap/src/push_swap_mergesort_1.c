/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mergesort_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:15:31 by hseong            #+#    #+#             */
/*   Updated: 2022/03/02 20:43:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_inst_func	g_prep_table[4] = {no_inst, sa, sb, ss};

static void		split_half(t_deque *deques[2]);
static void		prep_deques(t_deque *deques[2]);
static t_bool	item_comp(t_item a, t_item b, t_item tail);

void	push_swap_mergesort(t_deque *a, t_deque *b)
{
	t_deque	*deques[2];

	deques[0] = a;
	deques[1] = b;
	if ((deques[0])->size <= 1 || sort_check(a))
		return ;
	if ((deques[0])->size >= 4)
		split_half(deques);
	prep_deques(deques);
	while (sort_loop(deques))
		continue ;
}

void	split_half(t_deque *deques[2])
{
	t_deque	*a;
	size_t	idx;
	size_t	half;

	a = deques[0];
	idx = 0;
	half = a->size / 2;
	while (idx < half)
	{
		pb(deques);
		++idx;
	}
}

void	prep_deques(t_deque *deques[2])
{
	size_t	idx;
	size_t	flag;
	t_deque	*a;
	t_deque	*b;

	a = deques[0];
	b = deques[1];
	idx = 1;
	while (idx < a->size)
	{
		flag = 0;
		if (item_comp(a->head->item, a->head->next->item, a->tail->item))
			flag |= 1;
		if (idx < b->size
			&& item_comp(b->head->next->item, b->head->item, b->tail->item))
			flag |= 2;
		g_prep_table[flag](deques);
		if (idx + 1 < b->size)
			rr(deques);
		++idx;
	}
}

t_bool	item_comp(t_item a, t_item b, t_item tail)
{
	if ((a > b && (tail <= b || tail >= a))
		|| (a < b && b > tail && tail > a))
		return (TRUE);
	return (FALSE);
}
