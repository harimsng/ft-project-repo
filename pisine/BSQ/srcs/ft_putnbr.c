/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:21:41 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 19:45:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_num(int *nb);

void	ft_putnbr(int nb)
{
	int		denom;
	char	div;

	if (check_num(&nb))
		return ;
	denom = 1000000000;
	while (nb / denom == 0)
		denom /= 10;
	while (denom > 0)
	{
		div = nb / denom + '0';
		write(1, &div, 1);
		nb %= denom;
		denom /= 10;
	}
}

int	check_num(int *nb)
{
	if (*nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (*nb < 0)
	{
		write(1, "-", 1);
		if (*nb == -2147483648)
		{
			write(1, "2147483648", 10);
			return (1);
		}
		*nb *= -1;
	}
	return (0);
}
