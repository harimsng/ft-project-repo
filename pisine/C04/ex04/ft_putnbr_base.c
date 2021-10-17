/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:21:51 by hseong            #+#    #+#             */
/*   Updated: 2021/10/17 21:56:09 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_validity(char *base);
void	num_print(int nbr, char *base, int len);
int		int_min_check(int nbr, int len);

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;

	len = base_validity(base);
	if (len == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		int_min_check(nbr, len);
		nbr *= -1;
	}
	else if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	num_print(nbr, base, len);
}

int	base_validity(char *base)
{
	char	repeat[96];
	int		len;

	len = 0;
	while (len < 96)
		repeat[len++] = 0;
	len = 0;
	while (*base != 0)
	{
		if (repeat[*base - 32])
			return (1);
		else if (*base == '+' || *base == '-')
			return (1);
		repeat[*base - 32] = 1;
		++base;
		++len;
	}
	if (len < 2)
		return (1);
	return (len);
}

void	num_print(int nbr, char *base, int len)
{
	if (nbr == 0)
		return ;
	num_print((long long int)nbr / len, base, len);
	write(1, base + nbr % len, 1);
}

int	int_min_check(int nbr, int len)
{
	int		int_min;
	char	num;

	if (nbr == -2147483648)
	{
		int_min = (long long int)2147483648 / len;
		num_print( 
	}
}
