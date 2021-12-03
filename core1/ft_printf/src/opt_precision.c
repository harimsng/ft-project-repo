/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:17:14 by hseong            #+#    #+#             */
/*   Updated: 2021/12/03 21:39:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	integer_precision(t_format_info info, int len);

static char	*zeroes = "00000000000000000000000000000000\
00000000000000000000000000000000";

int	opt_precision(t_format_info info, char *buf, int len)
{
	int			ret;

	ret = 0;
	if (info.conv == 1)
		len -= (len > info.precision) * (len - info.precision);
	if (info.conv >= 3 && info.conv <= 7)
		ret += integer_precision(info, len - (buf[0] == '-'));
	return (ret + write(1, buf + (buf[0] == '-'), len));
}

static int	integer_precision(t_format_info info, int len)
{
	int		ret;
	int		num;

	ret = 0;
	num = info.precision - len;
	while (num > 0)
	{
		ret += write(1, zeroes, num * (num < 64)
				+ num * (num >= 64));
		num -= 64;
	}
	return (ret);
}
