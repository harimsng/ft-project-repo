/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:57:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 19:59:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	inst_rotation(a);
	write(1, "ra\n", 3);
}

void	rb(t_deque *b)
{
	inst_rotation(b);
	write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b)
{
	inst_rotation(a);
	inst_rotation(b);
	write(1, "rr\n", 3);
}
