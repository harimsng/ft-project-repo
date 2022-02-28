/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:52:27 by hseong            #+#    #+#             */
/*   Updated: 2022/03/01 00:26:52 by hseong           ###   ########.fr       */
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
	return (idx);
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
	delete_dlist(a, delete_item);
	delete_dlist(b, delete_item);
}
