#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(const char *s);

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

//	fd = 100;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || argc != 2)
		return (0);
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
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
