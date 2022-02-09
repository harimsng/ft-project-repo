/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_reverse_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:29:32 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:18:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	inst_revrot(t_deque *deque)
{
	if (deque->size <= 1)
		return ;
	push_front(deque, pop_back(deque));
}

void	inst_revrot_two(t_deque *first, t_deque *second)
{
	inst_revrot(first);
	inst_revrot(second);
}
