#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

static void	testfunc(void);

static const char	*g_sem_name = "/abc";

int	main(int argc, char *argv[])
{
	int		pid;
	sem_t	*sem_ptr;

	(void)argv;
	if (argc == 2)
	{
		if (sem_unlink(g_sem_name) != 0)
			perror("sem_unlink failed");
		else
			printf("sem_unlink succeeded\n");
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		testfunc();
		return (1);
	}
	if ((sem_ptr = sem_open(g_sem_name, O_CREAT, 0666, 1)) == SEM_FAILED)
	{
		printf("parent sem_open failed\n");
		perror(NULL);
	}
	else
		printf("parent sem_open succeeded\n");
	return (0);
}

void	testfunc(void)
{
	sem_t	*sem_ptr;

	sleep(1);
	if ((sem_ptr = sem_open(g_sem_name, 0)) == SEM_FAILED)
		printf("child sem_open failed\n");
	else
		printf("child sem_open succesed\n");
	sem_wait(sem_ptr);
	printf("child sem_wait succeeded\n");
}
