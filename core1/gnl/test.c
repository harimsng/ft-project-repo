#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*line;
	char	buf[10] = {'1', '1', '1', '1', '1', '1', '1', '1', '1'};

	(void)buf;
	(void)line;
	line = buf;
//	while (getc(stdin) != EOF)
//		printf(".\n");
	while (read(0, &(line++), 1) > 0)
		printf(".\n");
//	while ((line = get_next_line(0)))
//		printf("%s", line);
	
	return (0);
}
