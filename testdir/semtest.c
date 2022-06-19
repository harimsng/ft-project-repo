#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void	*test_sem_wait(void *arg);

static const char	*g_sem_name = "sem_test";

int	main(void)
{
	pthread_t	trd;
	sem_t		*sem;

	sem_unlink(g_sem_name);
	sem = sem_open(g_sem_name, O_CREAT, 0666, 1);
	pthread_create(&trd, NULL, test_sem_wait, sem);
	usleep(1000000);

	printf("main thread attempting to close sem\n");
	sem_close(sem);
	printf("main thread sem closed\n");
	pthread_join(trd, NULL);
	return (0);
}

void	*test_sem_wait(void *arg)
{
	printf("thread waiting sem\n");
	sem_wait(arg);
	printf("thread sem acquired\n");
	return (NULL);
}
