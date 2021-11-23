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
//	if (argc != 2)
//		return (0);
	(void)argv;
	(void)argc;
	fd = open("test", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = 1000;
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = open("test2", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = 1001; 
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = open("test3", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = 1002;
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = open("test4", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = 1003;
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = open("test5", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = 1004; 
	while ((line = get_next_line(fd)))
	{
		write(1, "_line_\n", 7);
		ft_putstr(line);
		free(line);
	}
	fd = open("test6", O_RDONLY);
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
