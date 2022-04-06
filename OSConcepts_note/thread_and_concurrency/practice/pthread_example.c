#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define NUM_THREADS (2)

typedef struct s_param
{
	int	start;
	int	end;
}		t_param;

static void	*runner_thread(void *param);
static void	*runner(void *param);
static int	bench_thread(int num);
static int	bench_nothread(int num);
static double	sqrtttt(int num);

int	main(int argc, char *argv[])
{
	clock_t		start;
	clock_t		end;
	double		time;
	int			sum;
	int			num = 0;

	if (argc != 2)
	{
		printf("./a.out  number\n");
		return (0);
	}
	num = atoi(argv[1]);

	start = clock();
	sum = bench_thread(num);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("sum = %d\n", sum);
	printf("bench_thread time = %lf\n", time);

	start = clock();
	sum = bench_nothread(num);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("sum = %d\n", sum);
	printf("bench_nothread time = %lf\n", time);
	return (0);
}

int	bench_thread(int num)
{
	t_param			range[NUM_THREADS];
	pthread_t		workers[NUM_THREADS];
	pthread_attr_t	attr;
	int				sum = 0;

	pthread_attr_init(&attr);
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		range[i] = (t_param){i * num, (i + 1) * num};
		pthread_create(workers + i, &attr, runner_thread, range + i);
	}
	for (int i = NUM_THREADS - 1; i >= 0; --i)
	{
		pthread_join(workers[i], NULL);
		sum += range[i].end;
	}
	return (sum);
}

int	bench_nothread(int num)
{
	int		sum;
	int		len = NUM_THREADS * num;
	t_param range = (t_param){0, len};

	runner(&range);
	sum = range.end;
	return (sum);
}

void	*runner_thread(void *param)
{
	t_param	*range = (t_param *)param;
	int		len = range->end;

	range->end = 0;
	for (int i = range->start; i < len; ++i)
		range->end += sqrtttt(i);
	pthread_exit(NULL);
	return (NULL);
}

void	*runner(void *param)
{
	t_param	*range = (t_param *)param;
	int		len = range->end;

	range->end = 0;
	for (int i = range->start; i < len; ++i)
		range->end += sqrtttt(i);
	return (NULL);
}

double	sqrtttt(int num)
{
	return sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(num)))))))));
}
