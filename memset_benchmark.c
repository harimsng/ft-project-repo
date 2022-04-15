#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define SIZE (1 << 20)

void	*ft_memset(void *addr, int val, size_t len);
void	*slow_memset(void *addr, int val, size_t len);
int		memset_check(void *addr, int val, size_t len);

int	main(void)
{
	clock_t	clock_time;
	double	time;
	char	buf[SIZE];
	char	buf2[SIZE];
	char	buf3[SIZE];
	char	buf4[SIZE];
	char	buf5[SIZE];
	char	buf6[SIZE];
//	timeval	time;
//	timeval time2;

//	gettimeofday(&time);
	clock_time = clock();
	memset(buf, 0, SIZE);
	clock_time = clock() - clock_time;
//	gettimeofday(&time2);
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	memset(buf2, 0, SIZE);
	clock_time = clock() - clock_time;
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	memset(buf3, 0, SIZE);
	clock_time = clock() - clock_time;
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	ft_memset(buf4, 0, SIZE);
	clock_time = clock() - clock_time;
//	gettimeofday(&time2);
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("ft_memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	ft_memset(buf5, 0, SIZE);
	clock_time = clock() - clock_time;
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("ft_memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	ft_memset(buf6, 0, SIZE);
	clock_time = clock() - clock_time;
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("ft_memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	slow_memset(buf4, 0, SIZE);
	clock_time = clock() - clock_time;
//	gettimeofday(&time2);
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("slow_memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	slow_memset(buf5, 0, SIZE);
	clock_time = clock() - clock_time;
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("slow_memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");

	clock_time = clock();
	slow_memset(buf6, 0, SIZE);
	clock_time = clock() - clock_time;
	time = (double)clock_time / CLOCKS_PER_SEC;
	printf("slow_memset time	= %lf\n", time);
	if (memset_check(buf, 0, SIZE))
		printf("memset failed\n");
	return (0);
}

void	*slow_memset(void *addr, int val, size_t len)
{
	unsigned char	*ptr = (unsigned char *)addr;
	unsigned char		v = (unsigned char)val;
	size_t				idx = 0;

	while (idx < len)
	{
		*ptr++ = v;
		++idx;
	}
	return (addr);
}

int		memset_check(void *addr, int val, size_t len)
{
	unsigned char	*ptr = (unsigned char *)addr;
	unsigned char		v = (unsigned char)val;
	size_t				idx = 0;

	while (idx < len)
	{
		if (ptr[idx] != v)
			return (1);
		++idx;
	}
	return (0);
}
