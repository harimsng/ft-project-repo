#include <unistd.h>

void	ft_putchar(char *str);

int	main(int argc, char **argv)
{
	if (argc > 0)
		ft_putchar(*argv);
	return (0);
}

void	ft_putchar(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		++str;
	}
}
