#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == 0)
	{
		if (s2 == 0)
			return (0);
		return (*s2);
	}
	if (s2 == 0)
		return (*s1);
	while (*s1 == *s2 && *s1 && *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strlen(char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		++len;
	return (len);
}
