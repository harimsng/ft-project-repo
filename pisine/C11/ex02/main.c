#include <stdio.h>

int	ft_any(char **tab, int (*f)(char *));
int	ft_str_is_alpha(char *str);

int	main(int argc, char **argv)
{
	int		idx;

	if (argc == 1)
		return (0);
	idx = 1;
	while (argv[idx])
		printf("%s\n", argv[idx++]);
	printf("%d\n", ft_any(argv + 1, ft_str_is_alpha));
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (*str < 'A' || (*str > 'Z' && *str < 'a') || *str > 'z')
			return (1);
		++str;
	}
	return (0);
}
