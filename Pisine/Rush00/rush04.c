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
