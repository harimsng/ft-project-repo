/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by hseong            #+#    #+#             */
/*   Updated: 2021/10/09 13:09:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	len_check(int len, int x, int y);

void	rush(int x, int y)
{
	int		len;

	len = 1;
	while (len <= x * y)
	{
		len_check(len, x, y);
		++len;
	}
}

void	len_check(int len, int x, int y)
{
	if (len == 1)
		ft_putchar('o');
	else if (len == x)
		ft_putchar('o');
	else if (len == x * (y - 1) + 1)
		ft_putchar('o');
	else if (len == x * y)
		ft_putchar('o');
	else if (len / x == 0)
		ft_putchar('-');
	else if (len % x == 1)
		ft_putchar('|');
	else if (len % x == 0)
		ft_putchar('|');
	else if (len / x == y - 1)
		ft_putchar('-');
	else
		ft_putchar(' ');
	if (len % x == 0)
		ft_putchar('\n');
}
