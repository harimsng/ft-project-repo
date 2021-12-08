/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:00:51 by hseong            #+#    #+#             */
/*   Updated: 2021/12/08 20:48:25 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*spaces = "                                \
                                00000000000000000000000000000000\
00000000000000000000000000000000";

int	opt_padding(t_format_info info, int len)
{
	int			ret;
	int			num;

	ret = 0;
	num = info.min_field;
	if (info.conv == 1)
		len -= (info.precision < len) * (len - info.precision);	
	else if (info.conv >= 3 && info.conv <= 7)
		len -= (info.precision > len) * (len - info.precision);
	len += !!(info.bit_flag & 60) + !!(info.bit_flag & 16);
	if (num <= len)
		return (0);
	num -= len;
	while (num > 0)
	{
		ret += write(1, spaces + 64 * (info.bit_flag & 2), 64 * (num >= 64)
			+ num * (num < 64));
		num -= 64;
	}
	return (ret);
}
