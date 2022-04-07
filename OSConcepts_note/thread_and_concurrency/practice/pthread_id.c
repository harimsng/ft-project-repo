#include <pthread.h>
#include <stdio.h>

void	*routine(void *);

int	main(void)
{
	pthread_t	thread[2];
	pthread_attr_t	attr;

	pthread_create(thread, &attr, routine, NULL);
	pthread_create(thread + 1, &attr, routine, NULL);
	printf("tid1 = %ld\n", (thread[0])->__sig);
	printf("tid2 = %ld\n", (thread[1])->__sig);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
}

void	*routine(void *arg)
{
	(void)arg;
	printf("rountine\n");
	return (NULL);
}
