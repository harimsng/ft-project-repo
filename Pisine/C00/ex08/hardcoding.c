#include <unistd.h>

int		power_of_ten(int n);
int		first_num(int n);
int		last_num(int n);
void	print_num(int num);
int		num_check(int num);

void	ft_print_combn(int n)
{
	int		idx;
	int		num;

	num = first_num(n);
	print_num(num);
	while ()
	{
		if (numcheck(num) == 1)
			print_num(num);
	}
}

int	power_of_ten(int n)
{
	int		ret;

	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	ret = 1;
	while (n > 0)
	{
		ret *= 10;
		--n;
	}
	return (ret);
}

int	first_num(int n)
{
	int		idx;
	int		zeroes;
	int		ret;

	ret = 0;
	idx = 0;
	zeroes = power_of_ten(n - 1);
	while (idx < n)
	{
		ret += idx * zeroes;
		zeroes /= 10;
		++idx;
	}
	return (ret);
}

int	last_num(int n)
{
