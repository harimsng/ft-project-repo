/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:20:23 by hseong            #+#    #+#             */
/*   Updated: 2022/03/05 18:14:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static const char	*g_inst_table[]
	= {
	"pa\n",
	"pb\n",
	"sa\n",
	"sb\n",
	"ss\n",
	"ra\n",
	"rb\n",
	"rr\n",
	"rra\n",
	"rrb\n",
	"rrr\n"
};

static void	flush_queue(t_dlist *queue, t_dlist *queue2);
static void	filter_inst(t_dlist *queue, t_dlist *queue2);
static void	check_inst(t_dlist *queue2);

void	inst_queue(int inst_idx)
{
	static t_dlist	queue = {NULL, NULL, NULL, 0, 0, 0};
	static t_dlist	queue2 = {NULL, NULL, NULL, 0, 0, 0};

	if (inst_idx == -1)
	{
		flush_queue(&queue, &queue2);
		return ;
	}
	push_back(&queue, inst_idx);
	if (queue.size == 3)
		filter_inst(&queue, &queue2);
	if (queue2.size == 3)
		check_inst(&queue2);
}

void	flush_queue(t_dlist *queue, t_dlist *queue2)
{
	int		idx;

	while (queue->size)
		push_back(queue2, pop_front(queue, delete_item));
	while (queue2->size)
	{
		idx = pop_front(queue2, delete_item);
		write(1, g_inst_table[idx], 3 + (idx > 7));
	}
}

void	filter_inst(t_dlist *queue, t_dlist *queue2)
{
	int		idx;
	int		jdx;
	int		inst_idx;

	idx = pop_front(queue, delete_item);
	jdx = pop_front(queue, delete_item);
	if ((idx + jdx == 1)
		|| (idx + jdx == 5 && idx * jdx == 6)
		|| (idx + jdx == 11 && idx * jdx == 30)
		|| (idx + jdx == 17 && idx * jdx == 72)
		|| (idx + jdx == 17 && idx * jdx == 70)
		|| (idx == 4 && jdx == 4))
	{
		inst_idx = 2 + (idx + jdx) / 2;
		if (idx * jdx != 0 && idx * jdx != 70 && !(idx == 4 && jdx == 4))
			push_back(queue2, inst_idx);
	}
	else
	{
		push_back(queue2, idx);
		push_back(queue2, jdx);
	}
}

void	check_inst(t_dlist *queue2)
{
	int		idx;
	int		jdx;
	int		inst_idx;

	idx = pop_front(queue2, delete_item);
	jdx = pop_front(queue2, delete_item);
	if ((idx + jdx == 1)
		|| (idx + jdx == 5 && idx * jdx == 6)
		|| (idx + jdx == 11 && idx * jdx == 30)
		|| (idx + jdx == 17 && idx * jdx == 72)
		|| (idx + jdx == 17 && idx * jdx == 70)
		|| (idx == 4 && jdx == 4))
	{
		inst_idx = 2 + (idx + jdx) / 2;
		if (idx * jdx != 0 && idx * jdx != 70 && !(idx == 4 && jdx == 4))
			write(1, g_inst_table[inst_idx], 3 + (inst_idx > 7));
	}
	else
	{
		write(1, g_inst_table[idx], 3 + (idx > 7));
		write(1, g_inst_table[jdx], 3 + (jdx > 7));
	}
}
