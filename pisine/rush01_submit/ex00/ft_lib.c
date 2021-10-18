/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:16:25 by hseong            #+#    #+#             */
/*   Updated: 2021/10/16 19:16:26 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_lib.h"

extern int	g_len;
extern int	*g_map;

void	ft_putstr(char *str)
{
	if (str == 0)
		return ;
	while (*str != 0)
		write(1, str++, 1);
}

int	max_change(int *a, int b)
{
	if (*a < b)
	{
		*a = b;
		return (1);
	}
	return (0);
}	

void	print_result(void)
{
	int			idx;
	char		num;

	idx = 0;
	while (idx < g_len * g_len)
	{
		num = g_map[idx] + '0';
		write(1, &num, 1);
		if (idx % g_len == g_len - 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		++idx;
	}
}
