/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:00:11 by hseong            #+#    #+#             */
/*   Updated: 2021/10/12 09:49:49 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		edge_case(int *n);

void	ft_putnbr(int nb)
{
	int		denom;
	char	num;

	if (edge_case(&nb))
		return ;
	denom = 1000000000;
	while (nb / denom == 0)
		denom /= 10;
	while (denom > 0)
	{
		num = '0' + nb / denom;
		nb -= (num - '0') * denom;
		write(1, &num, 1);
		denom /= 10;
	}
}	

int	edge_case(int *n)
{
	if (*n < 0)
	{
		write(1, "-", 1);
		if (*n == -2147483648)
		{
			write(1, "2147483648", 10);
			return (1);
		}
		*n *= -1;
	}
	else if (*n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}
