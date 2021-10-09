/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:00:30 by hseong            #+#    #+#             */
/*   Updated: 2021/10/09 13:05:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	len_check0(int len, int x, int y);
void	len_check1(int len, int x, int y);
void	len_check2(int len, int x, int y);
void	len_check3(int len, int x, int y);
void	len_check4(int len, int x, int y);

void	rush(int x, int y)
{
	int		len;
	int		subject_number;

	subject_number = 0;
	len = 1;
	if (subject_number == 0)
	{
		while (len <= x * y)
		{
			len_check0(len, x, y);
			++len;
		}
	}
	if (subject_number == 1)
	{
		while (len <= x * y)
		{
			len_check1(len, x, y);
			++len;
		}
	}
	if (subject_number == 2)
	{
		while (len <= x * y)
		{
			len_check2(len, x, y);
			++len;
		}
	}
	if (subject_number == 3)
	{
		while (len <= x * y)
		{
			len_check3(len, x, y);
			++len;
		}
	}
	if (subject_number == 4)
	{
		while (len <= x * y)
		{
			len_check4(len, x, y);
			++len;
		}
	}
}
void	len_check0(int len, int x, int y)
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

void	len_check1(int len, int x, int y)
{
	if (len == 1)
		ft_putchar('/');
	else if (len == x)
		ft_putchar('\\');
	else if (len == x * (y - 1) + 1)
		ft_putchar('\\');
	else if (len == x * y)
		ft_putchar('/');
	else if (len / x == 0)
		ft_putchar('*');
	else if (len / x == y - 1)
		ft_putchar('*');
	else if (len % x == 1)
		ft_putchar('*');
	else if (len % x == 0)
		ft_putchar('*');
	else
		ft_putchar(' ');
	if (len % x == 0)
		ft_putchar('\n');
}

void	len_check2(int len, int x, int y)
{
	if (len == 1)
		ft_putchar('A');
	else if (len == x)
		ft_putchar('A');
	else if (len == x * (y - 1) + 1)
		ft_putchar('C');
	else if (len == x * y)
		ft_putchar('C');
	else if (len / x == 0)
		ft_putchar('B');
	else if (len / x == y - 1)
		ft_putchar('B');
	else if (len % x == 1)
		ft_putchar('B');
	else if (len % x == 0)
		ft_putchar('B');
	else
		ft_putchar(' ');
	if (len % x == 0)
		ft_putchar('\n');
}

void	len_check3(int len, int x, int y)
{
	if (len == 1)
		ft_putchar('A');
	else if (len == x)
		ft_putchar('C');
	else if (len == x * (y - 1) + 1)
		ft_putchar('A');
	else if (len == x * y)
		ft_putchar('C');
	else if (len / x == 0)
		ft_putchar('B');
	else if (len / x == y - 1)
		ft_putchar('B');
	else if (len % x == 1)
		ft_putchar('B');
	else if (len % x == 0)
		ft_putchar('B');
	else
		ft_putchar(' ');
	if (len % x == 0)
		ft_putchar('\n');
}

void	len_check4(int len, int x, int y)
{
	if (len == 1)
		ft_putchar('A');
	else if (len == x)
		ft_putchar('C');
	else if (len == x * (y - 1) + 1)
		ft_putchar('C');
	else if (len == x * y)
		ft_putchar('A');
	else if (len / x == 0)
		ft_putchar('B');
	else if (len / x == y - 1)
		ft_putchar('B');
	else if (len % x == 1)
		ft_putchar('B');
	else if (len % x == 0)
		ft_putchar('B');
	else
		ft_putchar(' ');
	if (len % x == 0)
		ft_putchar('\n');
}
