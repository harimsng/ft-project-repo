/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:34:46 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 18:09:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(va_list arg)
{
	unsigned	num;
	unsigned	den;
	int			ret;

	num = va_arg(arg, unsigned);
	if (!num)
		return (write(1, "0", 1));
	den = 1000000000;
	while (!(num / den))
		den /= 10;
	ret = 0;
	while (den)
	{
		ret += write(1, hex_tab + (num / den), 1);
		num %= den;
		den /= 10;
	}
	return (ret);
}
