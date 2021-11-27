#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void	ft_putstr(const char *s);

int	main(int argc, char **argv)
{
	char	*line;
	int		fd[15];
	int		procedure[100] =
	{0, 0, 0, 1, 2,
	 3, 4, 5, 6, 1,
	 0, 1, 2, 3, 4,
	 13, 14, 14, 1, 1,
	 0, 7, 8, 9, 10,
	 11, 12, 13, 7, 8,
	 9, 10, 11, 12, 13,
	 0, 1, 13, 14, -1};
//	clock_t	start, end;
//	double	time;

//	fd = 100;
//	if (argc != 2)
//		return (0);
	(void)argv;
	(void)argc;
	fd[0] = 0;
	fd[1] = open("test1", O_RDONLY); 
	fd[2] = open("test2", O_RDONLY);
	fd[3] = open("test3", O_RDONLY);
	fd[4] = open("test4", O_RDONLY);
	fd[5] = open("test5", O_RDONLY);
	fd[6] = open("test6", O_RDONLY);
	fd[7] = open("test7", O_RDONLY);
	fd[8] = open("test8", O_RDONLY);
	fd[9] = open("test9", O_RDONLY);
	fd[10] = open("test10", O_RDONLY);
	fd[11] = open("test11", O_RDONLY);
	fd[12] = open("test12", O_RDONLY);
	fd[13] = open("test1_2", O_RDONLY);
	fd[14] = open("test1_3", O_RDONLY);

//	start = clock();
	for (int i = 0; procedure[i] != -1; ++i)
	{
		line = get_next_line(fd[procedure[i]]);
		if (!line)
			printf("line%d\t:(null)\n", i);
		else
			printf("line%d\t:|%s|\n", i, line);
		free(line);
	}
//	end = clock();
//	time = ((double)(end - start)) / (CLOCKS_PER_SEC);
//	printf("\ntime : %f\n", time);
	return (0);
}
void	ft_putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}
