#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int	main(void)
{
	pid_t	pid;

	if ((pid = fork()) == 0)
	{
		while (1)
		{
			printf("child process reporting\n");
			sleep(2);
		}
	}
	sleep(1);
	for (int i = 0; i < 5; ++i)
	{
		printf("waiting child process\n");
		waitpid(pid, NULL, WNOHANG);
		sleep(2);
	}
	printf("terminating child process\n");
	kill(pid, SIGINT);
	waitpid(pid, NULL, 0);
	printf("child process terminated\n");
	return (0);
}
