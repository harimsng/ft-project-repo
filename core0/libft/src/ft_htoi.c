/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:40:39 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 20:46:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	g_hex_table[23] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	0, 0, 0, 0, 0, 0, 0, 10, 11, 12,
	13, 14, 15
};

int	ft_htoi(const char *str)
{
	unsigned long long	num;
	unsigned long long	temp;

	while (ft_isspace(*str))
		++str;
	if (str[0] != '0' || str[1] != 'x')
		return (0);
	str += 2;
	num = 0;
	temp = 0;
	while (ft_ishex(*str) && temp <= num)
	{
		temp = num;
		num = 16 * num + g_hex_table[ft_toupper(*str++) - 48];
	}
	if (temp > num || num > LONG_MAX)
		return ((int)LONG_MAX);
	return ((int)num);
}
