#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

static const char	*g_sem_name = "/sem_flag_test";

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc > 1)
	{
		if (sem_unlink(g_sem_name) == 0)
			printf("sem_unlink successed\n");
		else
			perror("sem_unlink failed");
		return (0);
	}
	if (sem_open(g_sem_name, O_CREAT | O_EXCL, 0666, 1) == SEM_FAILED)
		printf("sem_open failed\n");
	else
		printf("sem_open successed\n");
	return (0);
}
