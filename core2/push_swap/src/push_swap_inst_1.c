/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:48:50 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 19:58:49 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_deque *a, t_deque *b)
{
	inst_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_deque *b, t_deque *a)
{
	inst_push(b, a);
	write(1, "pb\n", 3);
}

void	sa(t_deque *a)
{
	inst_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	inst_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	inst_swap(a);
	inst_swap(b);
	write(1, "ss\n", 3);
}
