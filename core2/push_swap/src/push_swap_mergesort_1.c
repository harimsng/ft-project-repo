/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mergesort_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:15:31 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 00:45:24 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_inst_func	g_prep_table[4] = {no_inst, sa, sb, ss};

static void		split_half(t_deque *a, t_deque *b);
static void		prep_deques(t_deque *a, t_deque *b);
static t_bool	a_item_comp(t_node *first, t_node *second, t_node *third);
static t_bool	b_item_comp(t_node *first, t_node *second, t_node *third);

void	push_swap_mergesort(t_deque *a, t_deque *b)
{
	if (a->size <= 1 || sort_check(a))
		return ;
	if (a->size >= 4)
		split_half(a, b);
	prep_deques(a, b);
	while (sort_cycle(a, b))
		continue ;
}

void	split_half(t_deque *a, t_deque *b)
{
	size_t	idx;
	size_t	half;

	idx = 0;
	half = a->size / 2;
	while (idx < half)
	{
		pb(a, b);
		++idx;
	}
}

void	prep_deques(t_deque *a, t_deque *b)
{
	size_t	idx;
	size_t	flag;

	idx = 1;
	while (idx < a->size)
	{
		flag = 0;
		if (a_item_comp(a->head, a->head->next, a->head->next->next))
			flag |= 1;
		if (idx < b->size
			&& b_item_comp(b->head, b->head->next, b->head->next->next))
			flag |= 2;
		g_prep_table[flag](a, b);
		if (idx + 1 < b->size)
			rrr(a, b);
		++idx;
	}
}

t_bool	a_item_comp(t_node *first, t_node *second, t_node *third)
{
	t_item		a;
	t_item		b;
	t_item		c;

	a = first->item;
	if (second == NULL)
		return (FALSE);
	b = second->item;
	if (third == NULL)
		return (a > b);
	c = third->item;
	return ((a < b && c < b && c > a)
		|| (a > b && (c < b || c > a)));
}

t_bool	b_item_comp(t_node *first, t_node *second, t_node *third)
{
	t_item		a;
	t_item		b;
	t_item		c;

	a = first->item;
	if (second == NULL)
		return (FALSE);
	b = second->item;
	if (third == NULL)
		return (b > a);
	c = third->item;
	return ((a > b && c > b && c < a)
		|| (a < b && (c > b || c < a)));
}
/*
static t_bool	item_comp(t_item a, t_item b, t_item tail);
t_bool	item_comp(t_item a, t_item b, t_item tail)
{
	if ((a > b && (tail <= b || tail >= a))
		|| (a < b && b > tail && tail > a))
		return (TRUE);
	return (FALSE);
}
*/
