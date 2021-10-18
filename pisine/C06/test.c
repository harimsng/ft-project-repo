#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*str;

	str = "abc";
	if (argc == 1)
		return (0);
	printf("%s\n", argv[1]);
	argv[1] = str;
	printf("%s\n", argv[1]);
	return (0);
}
