/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinkedlist_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:18:08 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 20:24:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlinkedlist.h"

void	print_node(t_node *node)
{
	dep_print_node(node);
}

void	print_dlist_foward(t_dlist *list)
{
	t_node	*node;
	size_t	idx;
	size_t	size;

	size = list->size;
	node = list->head;
	idx = 0;
	while (idx < size)
	{
		print_node(node);
		node = node->next;
		++idx;
	}
}

void	print_dlist_backward(t_dlist *list)
{
	t_node	*node;
	size_t	idx;
	size_t	size;

	size = list->size;
	node = list->tail;
	idx = size;
	while (idx > 0)
	{
		print_node(node);
		node = node->prev;
		--idx;
	}
}

void	ft_putnbr_space(int num)
{
	long long int	bignum;
	long long int	den;
	char			buf[12];
	int				idx;

	bignum = num;
	den = 1000000000;
	idx = num <= 0;
	buf[0] = '0' * (num == 0) + '-' * (num < 0);
	num *= 1 - 2 * (num < 0);
	while (den && !(bignum / den))
		den /= 10;
	while (den)
	{
		buf[idx++] = bignum / den + 48;
		bignum %= den;
		den /= 10;
	}
	buf[idx++] = ' ';
	write(1, buf, idx);
}
