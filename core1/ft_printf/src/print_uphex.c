/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:42 by hseong            #+#    #+#             */
/*   Updated: 2021/12/10 18:24:44 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		*str++ = g_hex_tab[16 + (num >> bits & 15)];
		bits -= 4;
	}
	*str = 0;
	return (0);
}
