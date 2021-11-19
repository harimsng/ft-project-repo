#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(const char *s);

int	main()
{
	char	*line;
	int		fd;

	fd = 0;
//	fd = open("test", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		ft_putstr(line);
		free(line);
	}
	return (0);	
}

void	ft_putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}
