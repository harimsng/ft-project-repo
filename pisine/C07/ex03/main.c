#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	char	*str;
	char	*sep;

	sep = ", ";
	str = ft_strjoin(argc - 1, argv + 1, sep);
	printf("%s\n", str);
	free(str);
	return (0);
}
