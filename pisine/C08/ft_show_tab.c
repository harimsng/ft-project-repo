/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:21:45 by hseong            #+#    #+#             */
/*   Updated: 2021/10/20 17:46:44 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stock_str.h"

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);

void	ft_show_tab(t_stock_str *par)
{
	if (!par)
		return ;
	while (par->str)
	{
		ft_putstr("test\n");
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
		++par;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nbr)
{
	char	num;

	if (!nbr)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr / 10)
		ft_putnbr(nbr / 10);
	num = nbr % 10 + '0';
	write(1, &num, 1);
}
