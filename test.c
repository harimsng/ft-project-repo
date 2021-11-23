#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	ssize_t		read_size;
	char		buf[65] = {0, };
	int			fd;
	int			idx;

	fd = 0;
//	fd = open("test", O_RDONLY);
	read_size = read(fd, buf, 64); 
	idx = 0;
	while (idx < 65)
	{
		if (buf[idx] == EOF)
			printf("EOF = %hhd\n", buf[idx]);
		++idx;
	}
	printf("read_size = %zd\n", read_size);
	ft_print_memory(buf, 72);
	return (0);
}
