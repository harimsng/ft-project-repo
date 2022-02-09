/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:02:07 by hseong            #+#    #+#             */
/*   Updated: 2022/02/09 20:24:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	inst_swap(t_deque *deque)
{
	t_node	*up;
	t_node	*down;

	up = deque->head;
	down = deque->head->prev;
	down->prev->next = up;
	up->prev = down->prev;
	up->next = down;
	down->prev = up;
	down->next = NULL;
	deque->head = down;
}

void	inst_swap_two(t_deque *first, t_deque *second)
{
	inst_swap(first);
	inst_swap(second);
}
