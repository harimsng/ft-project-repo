/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublyll_mergesort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:44:43 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 20:07:13 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublyll.h"

#include "../ft_debug.h"

static t_node	*split_list(t_node **head, size_t len);
static t_node	*join_list(t_node **headptr, t_node *mid, size_t len);
static void		move_node(t_node **sortnode, t_node **node, size_t *count);

void	mergesort_doublyll(t_doublyll *list)
{
	t_node	**headptr;
	t_node	*node;
	size_t	idx;
	size_t	size = list->size;

	headptr = &(list->head);
	if (headptr == NULL || *headptr == NULL || list->size == 1)
		return ;
	list->tail = split_list(headptr, list->size);
	idx = 1;
	node = *headptr;
	node->prev = NULL;
	while (idx < size)
	{
		node->next->prev = node;
		node = node->next;
		++idx;
	}
}

t_node	*split_list(t_node **headptr, size_t len)
{
	t_node		*mid;
	t_node		*tail;
	size_t		mid_len;
	size_t		idx;

	if (len < 2)
		return (*headptr);
	mid_len = len / 2;
	mid = *headptr;
	idx = 0;
	while (idx < mid_len)
	{
		mid = mid->next;
		++idx;
	}
	tail = split_list(headptr, len / 2);
	tail->next = mid;
	split_list(&(tail->next), (len + 1) / 2);
	return (join_list(headptr, tail->next, len));
}

t_node	*join_list(t_node **headptr, t_node *mid, size_t len)
{
	t_node	*head;
	t_node	*sortnode;
	size_t	head_count;
	size_t	mid_count;

	head = *headptr;
	head_count = len / 2;
	mid_count = (len + 1) / 2;
	if (head->item < mid->item)
		move_node(&sortnode, &head, &head_count);
	else
		move_node(&sortnode, &mid, &mid_count);
	*headptr = sortnode;
	while (--len)
	{
		if (head_count > 0 && (mid_count == 0 || head->item < mid->item))
			move_node(&(sortnode->next), &head, &head_count);
		else
			move_node(&(sortnode->next), &mid, &mid_count);
		sortnode = sortnode->next;
	}
	sortnode->next = NULL;
	return (sortnode);
}

static void		move_node(t_node **sortnode, t_node **node, size_t *count)
{
	*sortnode = *node;
	(*node) = (*node)->next;
	*count -= 1;
}
