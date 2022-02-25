/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:01:19 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 21:05:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	rra(t_deque *deques[2])
{
	inst_revrot(deques[0]);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *deques[2])
{
	inst_revrot(deques[1]);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *deques[2])
{
	inst_revrot(deques[0]);
	inst_revrot(deques[1]);
	write(1, "rrr\n", 4);
}

void	no_inst(t_deque *deques[2])
{
	(void)deques;
}
