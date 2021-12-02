/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:33:29 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 19:56:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(va_list arg, void *buf)
{
	char				*str;
	unsigned long long	num;
	int					bits;

	str = buf;
	num = (unsigned long long)(va_arg(arg, unsigned long long));
	bits = 60;
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
