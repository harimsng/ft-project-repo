/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:35:42 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 18:02:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uphex(va_list arg)
{
	unsigned	num;
	int			bits;
	int			ret;

	num = va_arg(arg, unsigned);
	bits = 28;
	while (bits && !(num >> bits & 15))
		bits -= 4;
	ret = 0;
	while (bits >= 0)
	{
		ret += write(1, hex_tab + 16 + (num >> bits & 15), 1);
		bits -= 4;
	}
	return (ret);
}
