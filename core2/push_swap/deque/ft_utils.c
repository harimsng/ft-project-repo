/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:12:55 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 22:36:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		++len;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	--n;
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
		--n;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
