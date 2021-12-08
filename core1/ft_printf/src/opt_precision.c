/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:17:14 by hseong            #+#    #+#             */
/*   Updated: 2021/12/08 19:13:20 by hseong           ###   ########.fr       */
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
//	printf("\ninfo\n");
//	printf("info.conv = %d\n", info.conv);
//	printf("info.precision = %d\n", info.precision);
//	printf("buf = %s\n", buf);
//	printf("len = %d\n", len);
	if (info.conv == 0)
	{
		write(1, buf, 1);
		return (1);
	}
	if (info.conv == 1)
	{
		len -= (info.precision && len > info.precision)
			* (len - info.precision);
		return ((write(1, buf, len)));
	}
	else if (info.conv >= 3 && info.conv <= 7)
	{
		len -= (buf[0] == '-')
			+ !!(info.bit_flag & 28) + !!(info.bit_flag & 16);
		ret += integer_precision(info, len);
	}
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
				+ 64 * (num >= 64));
		num -= 64;
	}
	return (ret);
}
