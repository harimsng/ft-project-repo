/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:59:54 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 18:18:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

static t_node	*split_list(t_node **head, size_t len);
static t_node	*join_list(t_node **headptr, t_node *mid, size_t len);
static void		move_node(t_node **sortnode, t_node **node, size_t *count);

void	mergesort_list(t_list *list)
{
	t_node	**headptr;

	headptr = &(list->head);
	if (headptr == NULL || *headptr == NULL || list->size == 1)
		return ;
	split_list(headptr, list->size);
}

t_node	*split_list(t_node **head, size_t len)
{
	t_node	*mid;
	t_node	*tail;
	size_t	mid_len;
	size_t	idx;

	if (len < 2)
		return (*head);
	mid = *head;
	mid_len = len / 2;
	idx = 0;
	while (idx < mid_len)
	{
		mid = mid->next;
		++idx;
	}
	tail = split_list(head, len / 2);
	tail->next = mid;
	split_list(&(tail->next), (len + 1) / 2);
	return (join_list(head, tail->next, len));
}

// DEBUG POINT
// 		... && (mid_count == 0 || head->item < mid->item)
// VS	... && (head->item < mid->item || mid_count == 0)
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

static void	move_node(t_node **sortnode, t_node **node, size_t *count)
{
	*sortnode = *node;
	*node = (*node)->next;
	*count -= 1;
}
