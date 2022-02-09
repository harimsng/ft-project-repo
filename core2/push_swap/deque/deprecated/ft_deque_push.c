/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:08:50 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 20:17:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	inst_push(t_deque *to, t_deque *from)
{
	t_node	*from_head;

	if (from->size == 0)
		return (0);
	from_head = from->head->prev;
	to->head->next = from->head;
	from->head->prev = to->head;
	to->head = from->head;
	from->head = from_head;
	++to->size;
	--from->size;
	return (1);
}
