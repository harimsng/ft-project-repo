/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:17:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 20:40:25 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	inst_rotation(t_deque *deque)
{
	if (deque->size == 0)
		return ;
	deque->head->next = deque->tail;
	deque->tail->prev = deque->head;
	deque->tail = deque->tail->prev;
	deque->tail->prev = NULL;
	deque->head = deque->head->prev;
	deque->head->next = NULL;
}

void	inst_rotation_two(t_deque *first, t_deque *second)
{
	inst_ratation(first);
	inst_ratation(first);
}
