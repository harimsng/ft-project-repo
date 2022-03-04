/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:52:27 by hseong            #+#    #+#             */
/*   Updated: 2022/03/04 00:23:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	sort_check(t_deque *a)
{
	size_t	size;

	if (a->size == 0)
		return (FALSE);
	a->cur = a->head;
	size = partial_check(&a->cur, a->size, HEAD, INC);
	return (size == a->size);
}

size_t	partial_check(t_node **ptr, size_t size, t_bool pos, t_bool dir)
{
	size_t	idx;
	t_node	*start;

	start = *ptr;
	idx = 0;
	if (pos == HEAD)
	{
		if (dir == INC)
			while (++idx < size && start->item < start->next->item)
				start = start->next;
		else
			while (++idx < size && start->item > start->next->item)
				start = start->next;
	}
	else
	{
		if (dir == INC)
			while (++idx < size && start->item < start->prev->item)
				start = start->prev;
		else
			while (++idx < size && start->item > start->prev->item)
				start = start->prev;
	}
	*ptr = start;
	return (idx * !!size);
}

// count number of blocks on a deque.
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
		if (size == 0)
			break ;
		node = node->next;
	}
	return (count);
}

void	print_data(t_deque *a, t_deque *b)
{
	ft_putstr_fd("deque A >> ", 1);
	print_dlist_forward(a, print_item);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("deque B >> ", 1);
	print_dlist_forward(b, print_item);
	ft_putstr_fd("\n", 1);
}

void	delete_data(t_deque *a, t_deque *b)
{
	empty_dlist(a, delete_item);
	empty_dlist(b, delete_item);
}
