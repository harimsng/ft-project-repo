/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:04 by hseong            #+#    #+#             */
/*   Updated: 2022/01/26 20:43:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_meta_list	meta_list;
	size_t		len;

	meta_list = (t_meta_list){NULL, 0};
	if (get_list(argc, argv, &meta_list) == 0)
		return print_error();
	push_swap(&meta_list);
	return (0);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}
