/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:31:28 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 12:56:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		int_min(int *num);

void	ft_itoa(int num)
{
	int	den;

	if (int_min(&num))
		return ;
	den = 1000000000;
	while (num / den == 0)
		den /= 10;
	while (den)
	{
		write(1, &("0123456789"[num / den]), 1);
		num %= den;
		den /= 10;
	}
}

int	int_min(int *num)
{
	if (*num == -2147483648)
	{
		write(1, "-2147483648", 11);
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
