#include "../includes/ft_hexd.h"

static const char	*hexarr = "0123456789abcdef";

void				print_read(int read_size);
void				print_hexrow(char *buf, int read_size);
void				print_content(char *buf, int read_size);
void				print_hex(char c);

int	print_input(char *filename, int option)
{
	char		buf[BUFLEN];
	int			read_size;
	int			fd;

	fd = 0;
	if (filename)
		fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	read_size = 0;
	print_read(read_size, option);
	read_size = read(fd, buf, BUFLEN);
	while (read_size > 0)
	{
		print_hexrow(buf, read_size);
		if (option)
			print_content(buf);
		read_size = read(fd, buf, BUFLEN);
		print_read(read_size, option);
	}
	if (read_size < 0)
	   return (1);
	if (fd > 0)
		close(fd);
	return (0);
}

void	print_read(int read_size, int option)
{
	char		nbr[8];
	int			idx;

	idx = 0;
	while (idx < 8)
		nbr[idx++] = 0;
	while (read_size && idx > 0)
	{
		nbr[--idx] = read_size % 10
		read_size /= 10;
	}
	write(1, nbr + !option, 7 + option);
}

void	print_hexrow(char *buf, int read_size)
{
	int			idx;

	idx = 0;
	while (idx < read_size)
	{
		if (option && (idx % 8 == 0))
			write(1, " ", 1);
		write(1, " ", 1);
		print_hex(buf[idx++]);	
	}
	while (idx < 16)
	{
		if (option && (idx % 8 == 0))
			write(1, " ", 1);
		write(1, "   ", 3);
		++idx;
	}
}

void	print_content(char *buf, int read_size)
{
	write(1, "  ", 2);
	write(1, "|", 1);
	write(1, buf, read_size);
}

void	print_hex(char c)
{
	write(1, hex_arr + (unsigned char)temp >> 4, 1);
	write(1, hex_arr + (unsigned char)temp & 15, 1);
}
