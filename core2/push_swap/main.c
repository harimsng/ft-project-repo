/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:11:57 by hseong            #+#    #+#             */
/*   Updated: 2022/01/27 20:25:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_meta_list	meta_list;

	meta_list = (t_meta_list){NULL, 0};
	if (get_list(argc, argv, &meta_list) == 0)
		return (print_error());
	print_list(&meta_list);
	push_swap(&meta_list);
	print_list(&meta_list);
	return (0);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
