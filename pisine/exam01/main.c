#include <stdio.h>

char	**ft_split(char *str);

int	main(int argc, char **argv)
{
	int		idx;
	char	**strarr;

	if (argc != 2)
		return (0);
	idx = 0;
	strarr = ft_split(argv[1]);
	while (strarr[idx] != NULL)
	{
		printf("%d\n", idx);
		printf("%p\n", strarr[idx]);
		printf("%s\n", strarr[idx]);
		++idx;
	}
	return (0);
}
