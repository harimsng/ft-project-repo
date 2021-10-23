/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:34:40 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 19:39:52 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_num(int *num);

void	ft_putnbr(int num)
{
	char	put;
	int		denom;

	if (check_num(&num))
		return ;
	denom = 1000000000;
	while (num / denom == 0)
		denom /= 10;
	while (denom > 0)
	{
		put = num / denom + '0';
		write(1, &put, 1);
		num = num % denom;
		denom /= 10;
	}
}

int	check_num(int *num)
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
