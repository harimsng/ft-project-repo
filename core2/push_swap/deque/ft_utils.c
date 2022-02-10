/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:12:55 by hseong            #+#    #+#             */
/*   Updated: 2022/02/10 16:00:14 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t		len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
}

void	ft_putnbr_space(int num)
{
	long long int	bignum;
	long long int	den;
	char			buf[12];
	int				idx;

	bignum = num;
	den = 1000000000;
	idx = bignum <= 0;
	buf[0] = '0' * (bignum == 0) + '-' * (bignum < 0);
	bignum *= 1 - 2 * (bignum < 0);
	while (den && !(bignum / den))
		den /= 10;
	while (den)
	{
		buf[idx++] = bignum / den + 48;
		bignum %= den;
		den /= 10;
	}
	buf[idx++] = ' ';
	write(1, buf, idx);
}
