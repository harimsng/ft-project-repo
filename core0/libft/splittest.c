#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**strarr;

	if (argc == 1 || argc > 2)
		return (0);
	strarr = ft_split(argv[1], 97);
	while (*strarr)
		printf("%s\n", *strarr++);
	return (0);
}
