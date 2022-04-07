#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%ld\n%d\n", time.tv_sec, time.tv_usec);
	return (0);
}
