/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_reverse_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:29:32 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 21:30:48 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

int	inst_revrot(t_deque *deque)
{
	deque->tail->prev = deque->head;
	deque->head->next = deque->tail;
	deque->head = deque->head->next;
	deque->head->next = NULL;
	deque->tail = deque->tail->prev;
	deque->tail->prev = NULL;
}
