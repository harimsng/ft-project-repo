#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char *str);

int	main(int argc, char **argv)
{
	char	*minptr;
	int		idx;
	int		jdx;

	idx = 1;
	while (idx < argc)
	{
		jdx = 1;
		while (jdx < argc - 1)
		{
			if (strcmp(argc[jdx], argc[jdx + 1]) < 0)
				minptr = argc + jdx;
			++jdx;
		}
		ft_putchar(*minptr);
		write(1, "\n", 1);
		++idx;
	}
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
