/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:57:43 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 16:29:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ra(t_deque *a, t_deque *b)
{
	(void)b;
	inst_rotation(a);
	if (a->flag == TRUE)
		inst_queue(5);
}

void	rb(t_deque *a, t_deque *b)
{
	(void)a;
	inst_rotation(b);
	if (a->flag == TRUE)
		inst_queue(6);
}

void	rr(t_deque *a, t_deque *b)
{
	inst_rotation(a);
	inst_rotation(b);
	if (a->flag == TRUE)
		inst_queue(7);
}
