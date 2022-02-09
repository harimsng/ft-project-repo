/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:08:50 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:20:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	inst_push(t_deque *to, t_deque *from)
{
	if (from->size == 0)
		return (0);
	push_front(to, pop_front(from));
	return (1);
}
