/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:50 by hseong            #+#    #+#             */
/*   Updated: 2022/03/02 22:44:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dlinkedlist.h"

int	push_front(t_dlist *list, t_item item)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	if (list->head == NULL)
		list->tail = new_node;
	else
		list->head->prev = new_node;
	new_node->item = item;
	new_node->next = list->head;
	new_node->prev = NULL;
	list->head = new_node;
	++list->size;
	return (1);
}

int	push_back(t_dlist *list, t_item item)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	if (list->tail == NULL)
		list->head = new_node;
	else
		list->tail->next = new_node;
	new_node->item = item;
	new_node->next = NULL;
	new_node->prev = list->tail;
	list->tail = new_node;
	++list->size;
	return (1);
}

t_item	pop_front(t_dlist *list, void (*delete_item)(t_item))
{
	t_node	*del_node;
	t_item	pop_item;

	if (list->head == NULL)
		return (0);
	del_node = list->head;
	pop_item = del_node->item;
	list->head = list->head->next;
	if (list->head != NULL)
		list->head->prev = NULL;
	else
		list->tail = NULL;
	delete_item(del_node->item);
	free(del_node);
	--list->size;
	return (pop_item);
}

t_item	pop_back(t_dlist *list, void (*delete_item)(t_item))
{
	t_node	*del_node;
	t_item	pop_item;

	if (list->tail == NULL)
		return (0);
	del_node = list->tail;
	pop_item = del_node->item;
	list->tail = list->tail->prev;
	if (list->tail != NULL)
		list->tail->next = NULL;
	else
		list->head = NULL;
	delete_item(del_node->item);
	free(del_node);
	--list->size;
	return (pop_item);
}
