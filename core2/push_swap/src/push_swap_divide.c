/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_divide.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:36:33 by hseong            #+#    #+#             */
/*   Updated: 2022/04/05 11:03:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_divide(t_deque *a_deque, t_deque *b_deque)
{
	size_t		idx;
	size_t		half;

	idx = 0;
	half = (a_deque->size + (a_deque->size > 10)) / 2;
	while (idx < half)
	{
		pb(a_deque, b_deque);
		++idx;
	}
}
