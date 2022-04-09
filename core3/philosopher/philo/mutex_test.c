#include <stdio.h>
#include <pthread.h>

void	*run(void *arg);

int	main(void)
{
	pthread_t	trd;
	pthread_mutex_t	mtx[2];

	pthread_mutex_init(mtx, NULL);
	pthread_mutex_init(mtx + 1, NULL);
	pthread_mutex_lock(mtx);
	printf("created\n");
	pthread_create(&trd, NULL, run, mtx);
	pthread_mutex_unlock(mtx);
	pthread_join(trd, NULL);
	printf("joined\n");
}

void	*run(void *arg)
{
	pthread_mutex_t	*mtx = arg;

	pthread_mutex_lock(mtx);
	pthread_mutex_lock(mtx + 1);
	printf("running\n");
	pthread_mutex_unlock(mtx);
	pthread_mutex_unlock(mtx + 1);
	return (NULL);
}
