/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:34:46 by hseong            #+#    #+#             */
/*   Updated: 2022/01/18 13:27:36 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*g_hex_tab = "0123456789";

int	print_unsigned(va_list arg, void *buf)
{
	char			*str;
	unsigned int	num;
	unsigned int	den;

	str = buf;
	num = va_arg(arg, unsigned);
	if (!num)
		return (ft_strlcpy(str, "0", NUMERIC_BUF_SIZE));
	den = 1000000000;
	while (!(num / den))
		den /= 10;
	while (den)
	{
		*str++ = g_hex_tab[num / den];
		num %= den;
		den /= 10;
	}
	*str = 0;
	return (0);
}
