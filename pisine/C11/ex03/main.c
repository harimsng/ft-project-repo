#include <stdio.h>

int	ft_count_if(char **tab, int length, int (*f)(char *));
int	ft_str_is_numeric(char *str);

int	main(int argc, char **argv)
{
	int			idx;

	if (argc == 1)
		return (0);
	idx = 1;
	while (idx < argc)
		printf("%s\n", argv[idx++]);
	printf("%d\n", ft_count_if(argv + 1, argc - 1, ft_str_is_numeric));
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		++str;
	}
	return (0);
}
