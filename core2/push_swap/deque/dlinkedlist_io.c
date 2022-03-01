/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:08 by hseong            #+#    #+#             */
/*   Updated: 2022/03/01 20:38:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlinkedlist.h"

void	dlist_init(t_dlist *list)
{
	*list = (t_dlist){NULL, NULL, NULL, 0, 0, 0};
}

void	print_dlist_forward(t_dlist *list, void (*print_item)(t_item))
{
	t_node	*node;
	size_t	idx;
	size_t	size;

	size = list->size;
	node = list->head;
	idx = 0;
	while (idx < size)
	{
		print_item(node->item);
		node = node->next;
		++idx;
	}
}

void	print_dlist_backward(t_dlist *list, void (*print_item)(t_item))
{
	t_node	*node;
	size_t	idx;
	size_t	size;

	size = list->size;
	node = list->tail;
	idx = size;
	while (idx > 0)
	{
		print_item(node->item);
		node = node->prev;
		--idx;
	}
}
