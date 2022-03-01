/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:13:10 by hseong            #+#    #+#             */
/*   Updated: 2022/03/01 18:17:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_edge(t_deque *deque, t_bool which)
{
	t_deque	*arr[2];

	if (which == TRUE)
	{
		arr[0] = deque;
		while (deque->head->item > deque->tail->item)
			rra(arr);
	}
	else if (deque->size > 1)
	{
		arr[1] = deque;
		while (deque->head->item < deque->tail->item)
			rrb(arr);
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
			break ;
		node = node->next;
	}
	return (count);
}
