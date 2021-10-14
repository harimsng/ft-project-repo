#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int		idx;

	if (argc == 1)
		return (0);
	idx = 1;
	while (idx < argc)
	{
		ft_putstr(argv[idx]);
		write(1, "\n", 1);
		++idx;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		++str;
	}
}
