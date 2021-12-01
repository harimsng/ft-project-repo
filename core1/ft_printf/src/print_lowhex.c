/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lowhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:13 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 18:02:30 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lowhex(va_list arg)
{
	unsigned	num;
	int			bits;
	int			ret;

	num = (unsigned)(va_arg(arg, unsigned));
	bits = 28; 
	ret = 0;
	while (bits && !(num >> bits & 15))
		bits -= 4;
	while (bits >= 0)
	{
		ret += write(1, hex_tab + (num >> bits & 15), 1);
		bits -= 4;
	}
	return (ret);
}
// no padding zeroes right after 0x
