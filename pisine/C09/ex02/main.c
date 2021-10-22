#include <stdlib.h>

#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
	char	*charset;
	char	**str_arr;
	char	**temp;

	charset = " ,";
	if (argc == 1)
	{
		printf("no input\n");
		return (0);
	}
	else if (argc == 2)
		printf("use default charset\n");
	else if (argc > 2)
	{
		printf("use custom charset\n");
		charset = argv[2];
	}
	str_arr = ft_split(argv[1], charset);
	temp = str_arr;
	while (*str_arr)
	{
		printf("%s\n", *str_arr);
		free(*str_arr);
		++str_arr;
	}
	free(temp);
	return (0);
}
