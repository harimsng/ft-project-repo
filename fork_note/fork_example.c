#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t	pid;
	int		child_return;

	sleep(1);
	printf("start fork\n");
	pid = fork();
	if (pid == 0)
	{
		printf("child process pid = %d\n", (int)getpid());
		sleep(3);
		printf("child process exit\n");
		exit(42);
	}
	pid = wait(&child_return);
	printf("exited child process id = %d\n", pid);
	printf("child process return = %d\n", child_return);
	printf("masking off = %d\n", WEXITSTATUS(child_return));

	printf("parent process pid = %d\n", (int)getpid());
	printf("parent process exit\n");
	return (0);
}
