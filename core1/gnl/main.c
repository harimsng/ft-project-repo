#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(const char *s);

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test2", O_RDONLY);
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
