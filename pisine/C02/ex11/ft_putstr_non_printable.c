/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:37:33 by hseong            #+#    #+#             */
/*   Updated: 2021/10/10 21:51:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char c);

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
	{
		if (*str < 32)
			print_hex(*str);
		else
			write(1, str, 1);
		++str;
	}
}

void	print_hex(char c)
{
	char	num;

	write(1, "\\", 1);
	if (c > 15)
	{
		write(1, "1", 1);
		c -= 16;
	}
	else
		write(1, "0", 1);
	if (c > 9)
	{
		num = 'a' + c - 10;
		write(1, &num, 1);
	}
	else
	{
		num = '0' + c;
		write(1, &num, 1);
	}
}
