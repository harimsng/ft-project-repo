/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:52:27 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 20:02:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_data(t_deque *a, t_deque *b)
{
	ft_putstr_fd("print deque A >> ", 1);
	print_dlist_forward(a, print_item);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("print deque B >> ", 1);
	print_dlist_forward(b, print_item);
	ft_putstr_fd("\n", 1);
}

void	delete_data(t_deque *a, t_deque *b)
{
	delete_dlist(a, delete_item);
	delete_dlist(b, delete_item);
}
