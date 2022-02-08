/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:02:25 by hseong            #+#    #+#             */
/*   Updated: 2022/02/06 21:11:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push_front(t_list *list, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (0);
	node->next = list->head;
	node->num = num;
	list->head = node;
	++list->size;
	return (1);
}

int	push_back(t_list *list, int num)
{
	t_node	**node_ptr;

	node_ptr = &list->head;
	while (*node_ptr != NULL)
		node_ptr = &(*node_ptr)->next;
	*node_ptr = malloc(sizeof(t_node));
	if (*node_ptr == NULL)
		return (0);
	(*node_ptr)->next = NULL;
	(*node_ptr)->num = num;
	++list->size;
	return (1);
}

void	pop_front(t_list *list)
{
	t_node	*node;

	node = list->head;
	list->head = node->next;
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
	free(*node_ptr);
	*node_ptr = NULL;
	--list->size;
}

void	print_list(t_node *node)
{
	while (node != NULL)
	{
		printf("%d\n", node->num);
		node = node->next;
	}
}
