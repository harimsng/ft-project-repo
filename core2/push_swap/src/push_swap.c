/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:15:31 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 21:29:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_half(t_deque *a, t_deque *b);
static void	first_sort(t_deque *a, t_deque *b);

void	push_swap(t_deque *a, t_deque *b)
{
	size_t		size;
	size_t		box;

	box = 2;
	size = a->size;
	split_half(a, b);
	first_sort(a, b);
	join_box(a, b);
}

void	split_half(t_deque *a, t_deque *b)
{
	size_t	idx;
	size_t	half;

	idx = 0;
	half = (a->size + 1) / 2;
	while (idx < half)
	{
		pb(b, a);
		++idx;
	}
}

void	first_sort(t_deque *a, t_deque *b)
{
	size_t	size;
	int		flag;

	flag = 0;
	size = a->size / 4;
	if (a->size % 4 > 0)
	{

	}
	while (size)
	{
		flag += (a->head->item > a->head->item)
			+ 2 * (b->head->item < b->head->next->item);
		if (flag == 1)
			sa(a);
		else if (flag == 2)
			sb(b);
		else if (flag == 3)
			ss(a, b);
		rr(a, b);
		rr(a, b);
		--size;
	}
}
