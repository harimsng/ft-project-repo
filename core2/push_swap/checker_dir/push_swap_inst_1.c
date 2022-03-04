/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:48:50 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 16:29:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	inst_push(a, b);
	if (a->flag == TRUE)
		inst_queue(0);
}

void	pb(t_deque *a, t_deque *b)
{
	inst_push(b, a);
	if (a->flag == TRUE)
		inst_queue(1);
}

void	sa(t_deque *a, t_deque *b)
{
	(void)b;
	inst_swap(a);
	if (a->flag == TRUE)
		inst_queue(2);
}

void	sb(t_deque *a, t_deque *b)
{
	(void)a;
	inst_swap(b);
	if (a->flag == TRUE)
		inst_queue(3);
}

void	ss(t_deque *a, t_deque *b)
{
	inst_swap(a);
	inst_swap(b);
	if (a->flag == TRUE)
		inst_queue(4);
}
