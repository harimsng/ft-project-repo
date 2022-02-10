/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:01:19 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 19:59:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *a)
{
	inst_revrot(a);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b)
{
	inst_revrot(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	inst_revrot(a);
	inst_revrot(b);
	write(1, "rrr\n", 4);
}
