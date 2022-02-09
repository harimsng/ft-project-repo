/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:17:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:20:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	inst_rotation(t_deque *deque)
{
	if (deque->size <= 1)
		return ;
	push_back(deque, pop_front(deque));
}

void	inst_rotation_two(t_deque *first, t_deque *second)
{
	inst_rotation(first);
	inst_rotation(second);
}
