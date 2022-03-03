/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:48:50 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 01:50:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	inst_push(a, b);
	if (a->flag == TRUE)
		write(1, "pa\n", 3);
}

void	pb(t_deque *a, t_deque *b)
{
	inst_push(b, a);
	if (a->flag == TRUE)
		write(1, "pb\n", 3);
}

void	sa(t_deque *a, t_deque *b)
{
	(void)b;
	inst_swap(a);
	if (a->flag == TRUE)
		write(1, "sa\n", 3);
}

void	sb(t_deque *a, t_deque *b)
{
	(void)a;
	inst_swap(b);
	if (a->flag == TRUE)
		write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	inst_swap(a);
	inst_swap(b);
	if (a->flag == TRUE)
		write(1, "ss\n", 3);
}
