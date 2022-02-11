/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:15:31 by hseong            #+#    #+#             */
/*   Updated: 2022/02/11 21:49:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_half(t_deque *a, t_deque *b);
static void	prep_blocks(t_deque *a, t_deque *b, size_t size);

void	push_swap(t_deque *a, t_deque *b)
{
	size_t		size;
	size_t		box;

	if (a->size <= 1)
		return ;
	box = 2;
	size = a->size;
	split_half(a, b);
	prep_blocks(a, b, size);
	while (sort_blocks(a, b))
		continue ;
}

// split data into two even-numbered deques.
// ex)	10 element -> a->size = 6, b->size = 4
// 		14 element -> a->size = 8, b->size = 6
//
// if a->size is odd number,
// a->size % 4 = 1 or 3.
// if number of leftover elements is 1,
// 		a has one more element.
// if it's 3,
// 		a has one more element.
// 		ex)	a->size = 2 + n, b->size = 1 + n
// 			sort two leftovers in a with sa(a)
//
// ex)	5 element -> a->size = 3, b->size = 2
// 		7 element -> a->size = 4, b->size = 3
void	split_half(t_deque *a, t_deque *b)
{
	size_t	idx;
	size_t	half;

	idx = 0;
	if (a->size % 4 == 2)
		half = a->size / 2 - 1;
	else
		half = a->size / 2;
	while (idx < half)
	{
		pb(b, a);
		++idx;
	}
}

void	prep_blocks(t_deque *a, t_deque *b, size_t size)
{
	size_t	modulus;
	int		flag;

	printf("a size = %zu\n", a->size);
	printf("b size = %zu\n", b->size);
	modulus = size % 4;
	size /= 4;
	while (size)
	{
		flag = (a->head->item > a->head->next->item)
			+ 2 * (b->head->item < b->head->next->item);
		if (flag == 1)
			sa(a);
		else if (flag == 2)
			sb(b);
		else if (flag == 3)
			ss(a, b);
		rrr(a, b);
		rrr(a, b);
		--size;
	}
	if (modulus & 2 && a->head->item > a->head->next->item)
		sa(a);
}
