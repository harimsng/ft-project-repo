#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_putnbr_fd(int num, int fd);

int	main(int argc, char *argv[])
{
	int		table[4000] = {0, };
	int		idx = 0;
	int		rand_num;
	int		numbers;
	int		file = open("testcase.txt", O_WRONLY | O_CREAT | O_TRUNC);
	clock_t	clock_num;

	clock_num = clock();
	srand((unsigned int)time(NULL) + (unsigned int)clock_num);
	if (argc != 2)
	{
		printf("input error: ./test (number of numbers)  #range: [0, 1000]");
		return (1);
	}
	numbers = atoi(argv[1]) % 1001;
	while (idx < numbers)
	{
		rand_num = (rand() - RAND_MAX / 2) % 2000;
		if (table[rand_num + 1999] == 0)
		{
			table[rand_num + 1999] = 1;
			ft_putnbr_fd(rand_num, file);
			++idx;
		}
	}
	close(file);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		buf[12];
	int			idx;
	int			denom;

	idx = 0;
	buf[idx] = '0';
	denom = 1000000000;
	if (n < 0)
	{
		buf[idx++] = '-';
		n *= -1;
	}
	while (n && (n / denom == 0))
		denom /= 10;
	while (denom > 0)
	{
		buf[idx++] = n / denom + 48;
		n %= denom;
		denom /= 10;
	}
	buf[idx++] = ' ';
	write(fd, buf, idx + !idx);
}
