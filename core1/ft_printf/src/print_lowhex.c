/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lowhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:13 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 19:34:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lowhex(va_list arg, void *buf)
{
	char		*str;
	unsigned	num;
	int			bits;

	str = buf;
	num = (unsigned)(va_arg(arg, unsigned));
	bits = 28; 
	while (bits && !(num >> bits & 15))
		bits -= 4;
	while (bits >= 0)
	{
		*str++ = hex_tab[num >> bits & 15];
		bits -= 4;
	}
	*str = 0;
	return (0);
}
// no padding zeroes right after 0x
