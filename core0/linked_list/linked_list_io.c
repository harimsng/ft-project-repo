/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_io.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:56:27 by hseong            #+#    #+#             */
/*   Updated: 2022/02/08 18:02:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	print_list(t_list *list)
{
	t_node	*node;

	node = list->head;
	while (node->next != NULL)
	{
		print_node(node);
		node = node->next;
	}
}

void	print_node(t_node *node)
{
	dep_print_node(node);
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
