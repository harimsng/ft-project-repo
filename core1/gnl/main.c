#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define TEST(i) ("test" #i)

void	ft_putstr(const char *s);

int	main(int argc, char **argv)
{
	char	*line;
	int		fd[257] = {0, };
//	int		procedure[300];
//	{0, 0, 0, 1, 2,
//	 3, 4, 5, 6, 1,
//	 1, 1, 2, 3, 4,
//	 13, 14, 14, 1, 1,
//	 2, 7, 8, 9, 10,
//	 11, 12, 13, 7, 8,
//	 9, 10, 11, 12, 13,
//	 3, 1, 13, 14, -1};
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
	fd[15] = open("test13", O_RDONLY);
	fd[16] = open("test14", O_RDONLY);
	fd[17] = open("test15", O_RDONLY);
	fd[18] = open("test16", O_RDONLY);
	fd[19] = open("test17", O_RDONLY);
	fd[20] = open("test18", O_RDONLY);
	fd[21] = open("test19", O_RDONLY);
	fd[22] = open("test20", O_RDONLY);
	fd[23] = open("test21", O_RDONLY);
	fd[24] = open("test22", O_RDONLY);
	fd[25] = open("test23", O_RDONLY);
	fd[26] = open("test24", O_RDONLY);
	fd[27] = open("test25", O_RDONLY);
	fd[28] = open("test26", O_RDONLY);
	fd[29] = open("test27", O_RDONLY);
	fd[30] = open("test28", O_RDONLY);
	fd[31] = open("test29", O_RDONLY);
	fd[32] = open("test30", O_RDONLY);
	fd[33] = open("test31", O_RDONLY);
	fd[34] = open("test32", O_RDONLY);
	fd[35] = open("test33", O_RDONLY);
	fd[36] = open("test34", O_RDONLY);
	fd[37] = open("test35", O_RDONLY);
	fd[38] = open("test36", O_RDONLY);
	fd[39] = open("test37", O_RDONLY);
	fd[40] = open("test38", O_RDONLY);
	fd[41] = open("test39", O_RDONLY);
	fd[42] = open("test40", O_RDONLY);
	fd[43] = open("test41", O_RDONLY);
	fd[44] = open("test42", O_RDONLY);
	fd[45] = open("test43", O_RDONLY);
	fd[46] = open("test44", O_RDONLY);
	fd[47] = open("test45", O_RDONLY);
	fd[48] = open("test46", O_RDONLY);
	fd[49] = open("test47", O_RDONLY);
	fd[50] = open("test48", O_RDONLY);
	fd[51] = open("test49", O_RDONLY);
	fd[52] = open("test50", O_RDONLY);
	fd[53] = open("test51", O_RDONLY);
	fd[54] = open("test52", O_RDONLY);
	fd[55] = open("test53", O_RDONLY);
	fd[56] = open("test54", O_RDONLY);
	fd[57] = open("test55", O_RDONLY);
	fd[58] = open("test56", O_RDONLY);
	fd[59] = open("test57", O_RDONLY);
	for (int i = 60; i < 257; ++i)
		fd[i] = i + 2;
//	start = clock();
	for (int i = 0; i < 257; ++i)
	{
		line = get_next_line(fd[i]);
		if (!line)
			printf("line%d\t:(null)\n", i);
		else
			printf("line%d\t:|%s|\n", i, line);
		free(line);
	}
	for (int i = 0; i < 257; ++i)
	{
		line = get_next_line(fd[i]);
		if (!line)
			printf("line%d\t:(null)\n", i);
		else
			printf("line%d\t:|%s|\n", i, line);
		free(line);
	}
//	end = clock();
//	time = ((double)(end - start)) / (CLOCKS_PER_SEC);
//	printf("\ntime : %f\n", time);
//	while (1)
//		continue ;
	return (0);
}

void	ft_putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}
