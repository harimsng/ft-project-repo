#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void	*lock(void *arg);

int	main(void)
{
	pthread_t	trd;

	lock(NULL);
	pthread_create(&trd, NULL, lock, NULL);
	printf("wating to join\n");
	pthread_detach(trd);
//	pthread_join(trd, NULL);
	usleep(1000000);
	return (0);
}

void	*lock(void *arg)
{
	static pthread_mutex_t	mtx;
	static int				init;

	(void)arg;
	if (init == 0)
	{
		pthread_mutex_init(&mtx, NULL);
		init = 1;
	}
	pthread_mutex_lock(&mtx);
	printf("mutex has been locked\n");
	return (NULL);
}
