#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(const char *s);

int	main(int argc, char **argv)
{
	char	*line;
	int		fd[5];

//	fd = 100;
//	if (argc != 2)
//		return (0);
	(void)argv;
	(void)argc;
	fd[0] = open("test", O_RDONLY);
	fd[1] = open("test2", O_RDONLY);
	fd[2] = open("test3", O_RDONLY);
	fd[3] = open("test4", O_RDONLY);
	fd[4] = open("test5", O_RDONLY);
	line = get_next_line(0);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[0]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[1]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[2]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[3]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
	ft_putstr(line);
		free(line);
	line = get_next_line(fd[1]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[2]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[1]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[3]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[1]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[3]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[1]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);
	line = get_next_line(fd[1]);
	write(1, "_line_\n", 7);
	if (!line)
		write(1, "(null)\n", 7);
	else
		ft_putstr(line);
	free(line);

	return (0);	
}

void	ft_putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}
