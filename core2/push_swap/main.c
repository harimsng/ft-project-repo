/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:11:57 by hseong            #+#    #+#             */
/*   Updated: 2022/02/06 21:12:33 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	list;

	list = (t_list){NULL, 0};
	if (get_list(argc, argv, &list) == 0)
		return (print_error());
	print_list(list.head);
	push_swap(&list);
	print_list(list.head);
	return (0);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
