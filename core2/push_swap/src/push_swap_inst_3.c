/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:01:19 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 01:50:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	rra(t_deque *a, t_deque *b)
{
	(void)b;
	inst_revrot(a);
	if (a->flag == TRUE)
		write(1, "rra\n", 4);
}

void	rrb(t_deque *a, t_deque *b)
{
	(void)a;
	inst_revrot(b);
	if (a->flag == TRUE)
		write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	inst_revrot(a);
	inst_revrot(b);
	if (a->flag == TRUE)
		write(1, "rrr\n", 4);
}

void	no_inst(t_deque *a, t_deque *b)
{
	(void)a;
	(void)b;
}
