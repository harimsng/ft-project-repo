#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	char	*bufptr;

	while ((bufptr = get_next_line(0)))
	{
		printf(">> %s\n", bufptr);
		free(bufptr);
	}
	return (0);
}
