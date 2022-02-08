/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:42 by hseong            #+#    #+#             */
/*   Updated: 2022/01/18 13:26:06 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*g_hex_tab = "0123456789ABCDEF";

int	print_uphex(va_list arg, void *buf)
{
	char			*str;
	unsigned int	num;
	int				bits;

	str = buf;
	num = va_arg(arg, unsigned);
	bits = 28;
	while (bits && !(num >> bits & 15))
		bits -= 4;
	while (bits >= 0)
	{
		*str++ = g_hex_tab[num >> bits & 15];
		bits -= 4;
	}
	*str = 0;
	return (0);
}
