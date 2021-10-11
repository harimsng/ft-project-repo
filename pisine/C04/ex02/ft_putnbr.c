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
		nb -= (div - '0') * denom;
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
