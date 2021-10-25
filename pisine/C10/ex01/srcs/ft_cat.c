#include "../includes/ft.h"

#define	BUF_LEN		30000

void	print_file(int fd);
int		get_files(char **argv);
void	error_check(int num, char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		print_file(0);
	else
		get_files(argv + 1);
	return (0);
}

void	print_file(int fd)
{
	char		buf[BUF_LEN + 1];
	int			read_size;

	while ((read_size = read(fd, buf, BUF_LEN)) > 0)
		write(1, buf, read_size);
	if (read_size < 0)
		error_check(read_size, 0);
}

int	get_files(char **argv)
{
	int			fd;

	while (*argv)
	{
		if ((*argv)[0] == '-' && (*argv)[1] == 0)
			print_file(0);
		else
		{
			if ((fd = open(*argv, O_RDONLY)) < 0)
				error_check(1, *argv);
			else
				print_file(fd);
		}
		++argv;
	}
	return (0);
}

void	error_check(int num, char *str)
{
	if (num == 0)
		return ;
	if (str && *str)
	{
		ft_puterr(str);
		ft_puterr(": ");
	}
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}
