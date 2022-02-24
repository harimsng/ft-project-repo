/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:13:10 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 01:22:08 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_edge(t_deque *deque, t_bool which)
{
	if (which == TRUE)
	{
		while (deque->head->item > deque->tail->item)
			rra(deque);
	}
	else if (deque->size > 1)
	{
		while (deque->head->item < deque->tail->item)
			rrb(deque);
	}
}

size_t	get_blocks(t_deque *deque, t_bool dir)
{
	size_t	count;
	size_t	size;
	t_node	*node;

	count = 0;
	size = deque->size;
	node = deque->head;
	while (TRUE)
	{
		size -= partial_check(&node, size, HEAD, dir);
		++count;
		if (node == deque->tail)
			break;
		node = node->next;
	}
	return (count);
}

void	move_block(t_deque *a, t_deque *b)
{

}
