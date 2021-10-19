#include <stdio.h>

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
	char	**str_arr;
	char	*charset;

	if (argc == 1)
		return (0);
	charset = ", :";
	str_arr = ft_split(argv[1], charset);
	while (*str_arr)
	{
		printf("%s\n", *str_arr);
		free(*str_arr);
		++str_arr;
	}
	return (0);
}
