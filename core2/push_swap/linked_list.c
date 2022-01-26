/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:02:25 by hseong            #+#    #+#             */
/*   Updated: 2022/01/26 20:30:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_front(t_meta_list *meta_list, int num)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (0);
	node->next = meta_list->head;
	node->num = num;
	meta_list->head = node;
	++meta_list->size;
	return (1);
}

int	push_back(t_meta_list *meta_list, int num)
{
	t_list	*node;

	node = meta_list->head;
	while (node != NULL)
		node = node->next;
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (0);
	node->next = NULL;
	node->num = num;
	++meta_list->size;
	return (1);
}

void	pop_front(t_meta_list *meta_list, int num)
{
	t_list	*node;

	node = meta_list->head;
	meta_list->head = node->next;
	free(node);
	--meta_list->size;
}

void	pop_back(t_meta_list *meta_list, int num)
{
	t_list	**node_ptr;

	if (meta_list->size == 0)
		return ;
	node_ptr = &t_meta_list->head;
	while ((*node_ptr)->next != NULL)
		node_ptr = &(*node_ptr)->next;
	free(*node_ptr);
	*node_ptr = NULL;
	--meta_list->size;
}
