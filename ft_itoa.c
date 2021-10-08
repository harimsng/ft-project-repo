#include <unistd.h>

#define LEN	10

void	ft_putstr(char *str);

void	ft_itoa(int i, char *str);

void	ft_swap(char *a, char *b);

int	main(void)
{
	int		left;
	char	str[LEN];

	left = 12345;
	ft_itoa(left, str);
	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}

void	ft_itoa(int i, char *str)
{
	int		len;
	char	*start;

	if (i == 0)
	{
		str[0] = 0;
		str[1] = '\0';
	}
	start = str;
	len = 0;
	while (i > 0)
	{
		*str = '0' + i % 10;
		i /= 10;
		++len;
		++str;
	}
	*str = '\0';
	--str;
	while (start < str)
		ft_swap(start++, str--);
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
