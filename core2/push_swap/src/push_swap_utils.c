/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:52:27 by hseong            #+#    #+#             */
/*   Updated: 2022/02/14 21:32:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	sort_check(t_deque *a)
{
	t_node	*trav;
	size_t	idx;
	size_t	size;

	trav = a->head;
	idx = 1;
	size = a->size;
	while (idx < size)
	{
		if (trav->item > trav->next->item)
			return (FALSE);
		trav = trav->next;
		++idx;
	}
	return (TRUE);
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
