#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOOP (1000000)

int	bench_rand(void)
{
	const double	rand_max_2 = RAND_MAX / 2;
	double	num;
	int		idx = 0;
	int		sum = 0;

	while (idx < MAX_LOOP)
	{
		num = (double)rand();
		if (num > rand_max_2)
			++sum;
		++idx;
	}
	return (sum);
}

int	bench_norand(void)
{
	const double	rand_max_2 = RAND_MAX / 2;
	double	num;
	int		idx = 0;
	int		sum = 0;

	while (idx < MAX_LOOP)
	{
		num = (double)rand();
		if (num + RAND_MAX / 2 > rand_max_2)
			++sum;
		++idx;
	}
	return (sum);
}

int	main(void)
{
	clock_t	start;
	clock_t	end;
	double	time1, time2;
	int		sum1, sum2;

	srand(clock());
	start = clock();
	sum1 = bench_rand();
	end = clock();
	time1 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	sum2 = bench_norand();
	end = clock();
	time2 = (double)(end - start) / CLOCKS_PER_SEC;

	printf("rand time = %lf, sum = %d\nnorand time = %lf, sum = %d\n", time1, sum1, time2, sum2);
}
