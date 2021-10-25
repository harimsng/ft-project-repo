/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:31:28 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 20:31:30 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		long_min(long long *num);

void	ft_ltoa(long long num)
{
	long long	den;

	if (long_min(&num))
		return ;
	den = 1000000000000000000;
	while (num / den == 0)
		den /= 10;
	while (den)
	{
		write(1, &("0123456789"[num / den]), 1);
		num %= den;
		den /= 10;
	}
}

int	long_min(long long *num)
{
	if (*num == -9223372036854775807)
	{
		write(1, "-9223372036854775807", 20);
		return (1);
	}
	else if (*num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (*num < 0)
	{
		write(1, "-", 1);
		*num *= -1;
		return (0);
	}
	return (0);
}
