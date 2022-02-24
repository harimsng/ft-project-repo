/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mergesort_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:15:31 by hseong            #+#    #+#             */
/*   Updated: 2022/02/24 18:52:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		split_half(t_deque *a, t_deque *b);
static void		prep_blocks(t_deque *a, t_deque *b);
static t_bool	item_comp(t_item a, t_item b, t_item tail);

void	push_swap_mergesort(t_deque *a, t_deque *b)
{
	if (a->size <= 1)
		return ;
	if (a->size >= 4)
		split_half(a, b);
	prep_blocks(a, b);
	while (sort_loop(a, b))
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
		pb(b, a);
		++idx;
	}
}
// a-> size >= b->size

/*
void	prep_blocks(t_deque *a, t_deque *b)
{

}
*/
void	prep_blocks(t_deque *a, t_deque *b)
{
	size_t	idx;
	size_t	flag;

	idx = 1;
	while (idx < a->size)
	{
		flag = 0;
		if (item_comp(a->head->item, a->head->next->item, a->tail->item))
		if (idx < b->size
			&& item_comp(b->head->next->item, b->head->item, b->tail->item))
/*
		if ((a->head->next->item < a->head->item
			&& a->tail->item > a->head->item)
			|| ())

			&& (a->tail->item <= a->head->next->item
			|| a->tail->item > a->head->item))
			flag |= 1;
		if (idx < b->size
			&& b->head->next->item > b->head->item
			&& (b->tail->item >= b->head->next->item
			|| b->tail->item < b->head->item))
			flag |= 2;
			*/
		if (flag == 1)
			sa(a);
		else if (flag == 2)
			sb(b);
		else if (flag == 3)
			ss(a, b);
		if (idx < b->size - 1)
			rr(a, b);
		++idx;
	}
}

t_bool	item_comp(t_item a, t_item b, t_item tail)
{
	if ((b > a && tail <= b && tail >= a)
		|| (a < b && b > tail))
		return (true);
}
