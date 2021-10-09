#include <unistd.h>

void	int_max_print(void);

void	ft_putnbr(int n)
{
	int		denom;
	char	num;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			int_max_print();
			return ;
		}
		n *= -1;
	}
	denom = 1000000000;
	while (n / denom == 0)
		denom /= 10;
	while (denom > 0)
	{
		num = '0' + n / denom;
		n -= (num - '0') * denom;
		write(1, &num, 1);
		denom /= 10;
	}
}	

void	int_max_print(void)
{
	write(1, "2", 1);
	write(1, "1", 1);
	write(1, "4", 1);
	write(1, "7", 1);
	write(1, "4", 1);
	write(1, "8", 1);
	write(1, "3", 1);
	write(1, "6", 1);
	write(1, "4", 1);
	write(1, "8", 1);
}
