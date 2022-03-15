#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**temp;
	char	**strarr;

/*	strarr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspe    ndisse", 32);
	temp = strarr;
	while (*strarr)
	{
		printf("%s\n", *strarr);
		free(*strarr++);
	}
	free(*strarr);
	free(temp);
	*/
	printf("commandline arg\n");
	if (argc == 1 || argc > 2)
		return (0);
	strarr = ft_split(argv[1], 32);
	temp = strarr;
	while (*strarr)
	{
		printf("%s\n", *strarr);
		free(*strarr++);
	}
	free(*strarr);
	free(temp);
	
	return (0);
}
