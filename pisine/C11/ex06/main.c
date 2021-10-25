#include <stdio.h>

void	ft_sort_string_tab(char **tab);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	ft_sort_string_tab(argv + 1);
	++argv;
	while (*argv)
		printf("%s\n", *argv++);
	return (0);
}
