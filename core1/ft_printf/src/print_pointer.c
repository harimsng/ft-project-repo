/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:33:29 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 18:02:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_lllowhex(va_list arg);

int	print_pointer(va_list arg)
{
	return (write(1, "0x", 2) + print_lllowhex(arg));
}

static int	print_lllowhex(va_list arg)
{
	unsigned long long	num;
	int					bits;
	int					ret;

	num = (unsigned long long)(va_arg(arg, unsigned long long));
	bits = 60;
	while (bits && !(num >> bits & 15))
		bits -= 4;
	ret = 0;
	while (bits >= 0)
	{
		ret += write(1, hex_tab + (num >> bits & 15), 1);
		bits -= 4;
	}
	return (ret);
}
