/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:59:54 by hseong            #+#    #+#             */
/*   Updated: 2022/01/27 21:01:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_list(t_list *head, size_t size);
static void	join_list(t_list **head_ptr, t_list *mid, size_t size);

void	mergesort_list(t_list *head)
{
	t_list	*tail;
	size_t	size;

	if (head == NULL)
		return ;
	size = 1;
	tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
		++size;
	}
	DEBUG("size = %zu", size);
	split_list(head, size);
}

void	split_list(t_list *head, size_t size)
{
	t_list	*mid;
	size_t	mid_len;

	if (size < 2)
		return ;
	mid = head;
	mid_len = size / 2;
	DEBUG("size = %zu, mid = %zu", size, mid_len);
	while (mid_len)
		mid = mid->next;
	split_list(head, size / 2);
	split_list(mid, (size + 1) / 2);
	join_list(&head, mid, size);
}

void	join_list(t_list **head_ptr, t_list *mid, size_t size)
{
	t_list	*head;
	t_list	*sortnode;
	t_list	**temp_ptr;
	t_list	*mid_bound;
	size_t	head_count;
	size_t	mid_count;

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
	while (--size)
		sortnode = sortnode->next;
	sortnode->next = NULL;
}
