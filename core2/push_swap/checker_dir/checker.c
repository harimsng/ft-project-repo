/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:31:52 by hseong            #+#    #+#             */
/*   Updated: 2022/03/01 20:36:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

int			get_list(int argc, char *argv[], t_deque *deque);
static void	print_error(void);

int	main(int argc, char *argv[])
{
	t_deque			a_deque;
	t_deque			b_deque;
	unsigned int	result_bit;

	dlist_init(&a_deque);
	dlist_init(&b_deque);
	a_deque.flag = FALSE;
	if (argc == 1)
		return (0);
	if (get_list(argc, argv, &a_deque) == 0)
	{
		delete_data(&a_deque, &b_deque);
		print_error();
		return (1);
	}
	result_bit = check_inst(&a_deque, &b_deque);
	if (result_bit == OK_BIT)
		write(1, "OK\n", 3);
	else if (result_bit == KO_BIT)
		write(1, "KO\n", 3);
	else
		print_error();
	delete_data(&a_deque, &b_deque);
	return (0);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}
