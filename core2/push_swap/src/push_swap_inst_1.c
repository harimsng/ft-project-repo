/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:48:50 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 21:07:11 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	pa(t_deque *deques[2])
{
	inst_push(deques[0], deques[1]);
	write(1, "pa\n", 3);
}

void	pb(t_deque *deques[2])
{
	inst_push(deques[1], deques[0]);
	write(1, "pb\n", 3);
}

void	sa(t_deque *deques[2])
{
	inst_swap(deques[0]);
	write(1, "sa\n", 3);
}

void	sb(t_deque *deques[2])
{
	inst_swap(deques[1]);
	write(1, "sb\n", 3);
}

void	ss(t_deque *deques[2])
{
	inst_swap(deques[0]);
	inst_swap(deques[1]);
	write(1, "ss\n", 3);
}
