/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:02:25 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 17:15:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linked_list.h>

int	push_front(t_list *list, t_item item)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (0);
	node->next = list->head;
	node->item = item;
	list->head = node;
	++list->size;
	return (1);
}

int	push_back(t_list *list, t_item item)
{
	t_node	**node_ptr;

	node_ptr = &list->head;
	while (*node_ptr != NULL)
		node_ptr = &(*node_ptr)->next;
	*node_ptr = malloc(sizeof(t_node));
	if (*node_ptr == NULL)
		return (0);
	(*node_ptr)->next = NULL;
	(*node_ptr)->item = item;
	++list->size;
	return (1);
}

void	pop_front(t_list *list)
{
	t_node	*node;

	if (list->size == 0)
		return ;
	node = list->head;
	list->head = node->next;
	dep_delete_item(node->item);
	free(node);
	--list->size;
}

void	pop_back(t_list *list)
{
	t_node	**node_ptr;

	if (list->size == 0)
		return ;
	node_ptr = &list->head;
	while ((*node_ptr)->next != NULL)
		node_ptr = &(*node_ptr)->next;
	dep_delete_item((*node_ptr)->item);
	free(*node_ptr);
	*node_ptr = NULL;
	--list->size;
}
