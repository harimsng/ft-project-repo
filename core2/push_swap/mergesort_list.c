/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:59:54 by hseong            #+#    #+#             */
/*   Updated: 2022/02/06 21:14:23 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		split_list(t_node **head, size_t size);
static void		join_list(t_node **head_ptr, t_node *mid, size_t size);
static t_node	*head_access(t_node *head);

void	mergesort_list(t_node **head)
{
	t_node	*tail;
	size_t	size;

	if (head == NULL || *head == NULL)
		return ;
	head_access(*head);
	size = 1;
	tail = *head;
	while (tail->next != NULL)
	{
		tail = tail->next;
		++size;
	}
	DEBUG("size = %zu", size);
	split_list(head, size);
}

void	split_list(t_node **head, size_t size)
{
	t_node	**mid;
	size_t	mid_len;
	size_t	idx;

	if (size < 2)
		return ;
	mid = head;
	mid_len = size / 2;
	DEBUG("size = %zu, mid = %zu", size, mid_len);
	idx = 0;
	while (idx < mid_len)
	{
		mid = &(*mid)->next;
		++idx;
	}
	split_list(head, size / 2);
	split_list(mid, (size + 1) / 2);
	join_list(head, *mid, size);
}

void	join_list(t_node **head_ptr, t_node *mid, size_t size)
{
	t_node	*head;
	t_node	*sortnode;
	t_node	**temp_ptr;
	t_node	*mid_bound;
	size_t	head_count;
	size_t	mid_count;

	DEBUG("size = %zu", size);
	head_count = size / 2;
	mid_count = (size + 1) / 2;
	mid_bound = mid;
	head = *head_ptr;
	if (head->num > mid->num)
		temp_ptr = &mid;
	else
		temp_ptr = &head;
	--size;
	sortnode = *temp_ptr;
	*head_ptr = sortnode;
	*temp_ptr = (*temp_ptr)->next;
	while (head_count && mid_count)
	{
		if (head->num > mid->num)
		{
			temp_ptr = &mid;
			--mid_count;
		}
		else
		{
			temp_ptr = &head;
			--head_count;
		}
		sortnode->next = *temp_ptr;
		sortnode = sortnode->next;
		*temp_ptr = (*temp_ptr)->next;
		--size;
	}
	sortnode->next = head;
	if (head_count == 0)
		sortnode->next = mid;
	while (size--)
		sortnode = sortnode->next;
	sortnode->next = NULL;
	print_list(head_access(NULL));
}

static t_node *head_access(t_node *head)
{
	static t_node	*list_head;
	if (head != NULL)
		list_head = head;
	return (list_head);
}
