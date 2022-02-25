/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:57:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 21:05:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ra(t_deque *deques[2])
{
	inst_rotation(deques[0]);
	write(1, "ra\n", 3);
}

void	rb(t_deque *deques[2])
{
	inst_rotation(deques[1]);
	write(1, "rb\n", 3);
}

void	rr(t_deque *deques[2])
{
	inst_rotation(deques[0]);
	inst_rotation(deques[1]);
	write(1, "rr\n", 3);
}
