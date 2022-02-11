#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	bool	flag = 1;
	char	*test = malloc(1);
	printf("%c\n", *test);
	printf("%c\n", (char)flag);
	return (0);
}
