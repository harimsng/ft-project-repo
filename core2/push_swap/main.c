/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:11:57 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 20:39:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deque	a_deque, b_deque;

	dlist_init(&a_deque);
	dlist_init(&b_deque);
	if (get_list(argc, argv, &a_deque) == 0)
		return (print_error());
	push_swap(&a_deque, &b_deque);
	print_data(&a_deque, &b_deque);
	delete_data(&a_deque, &b_deque);
	return (0);
}

int	print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	return (1);
}
