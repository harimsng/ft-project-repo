/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:34:14 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 19:51:19 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list arg, void *buf)
{
	char		*str;
	int			num;
	int			den;

	str = buf;
	num = va_arg(arg, int);
	if (num == -2147483648)
		return (!(int)ft_strlcpy(str, "-2147483648", NUMERIC_BUF_SIZE));
	else if (num == 0)
		return (!(int)ft_strlcpy(str, "0", NUMERIC_BUF_SIZE));
	else if (num < 0)
		*str++ = '-';
	num *= 1 - 2 * (num < 0);
	den = 1000000000;
	while (!(num / den))
		den /= 10;
	while (num > 0)
	{
		*str++ = num / den + '0';
		num %= den;
		den /= 10;
	}
	*str = 0;
	return (0);
}
