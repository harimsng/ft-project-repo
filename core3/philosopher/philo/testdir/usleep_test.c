#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	int		time;
	int		measure;
	struct timeval get_time;

	for (time = 1000; time <= 1000000; time *= 10)
	{
		gettimeofday(&get_time, NULL);
		measure = get_time.tv_sec * 1000000 + get_time.tv_usec;
		usleep(time);
		gettimeofday(&get_time, NULL);
		measure = get_time.tv_sec * 1000000 + get_time.tv_usec - measure;
		printf("expected usleep(%d) = %lf ms = %lf s\n",
				time, (double)time / 1000, (double)time / 1000000);
		printf("measured usleep(%d) = %lf ms = %lf s\n",
				time, (double)measure / 1000, (double)measure / 1000000);
	}
	return (0);
}
