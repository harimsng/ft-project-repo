/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:37:33 by hseong            #+#    #+#             */
/*   Updated: 2021/10/16 22:15:14 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char c);

void	ft_putstr_non_printable(char *str)
{
	if (str == 0)
		return ;
	while (*str != 0)
	{
		if (*str < 32 || *str == 127)
		{
			write(1, "\\", 1);
			print_hex((unsigned char)*str >> 4);
			print_hex(*str & 15);
		}
		else
			write(1, str, 1);
		++str;
	}
}

// unsigned bitshift example
// 1010 >> 2 = 0010 = (10 / 2) / 2 = 2
// signed bitshift
// 1010 >> 2 = 1110 = (-10 / 2) / 2 = -2
void	print_hex(char c)
{
	char	num;

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
