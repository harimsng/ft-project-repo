#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int		out_fd;
	int		temp_fd;

	out_fd = open("testout.txt", O_CREAT | O_WRONLY, 0777);
	temp_fd = dup(1);
	dup2(out_fd, 1);
	write(out_fd, "out_fd\n", 7);
	write(temp_fd, "temp_fd\n", 8);
}
