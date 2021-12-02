/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:42 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 19:59:25 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uphex(va_list arg, void *buf)
{
	char		*str;
	unsigned	num;
	int			bits;

	str = buf;
	num = va_arg(arg, unsigned);
	bits = 28;
	while (bits && !(num >> bits & 15))
		bits -= 4;
	while (bits >= 0)
	{
		*str++ = hex_tab[16 + (num >> bits & 15)];
		bits -= 4;
	}
	*str = 0;
	return (0);
}
