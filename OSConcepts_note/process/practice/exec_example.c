#include <stdio.h>
#include <unistd.h>

int	child_process(void);

int	main(void)
{
	if (fork() == 0)
		return (child_process());
	printf("parent process: %d\n", getpid());
	sleep(1);
	return (0);
}

int	child_process(void)
{
	printf("child process start\n");
	execlp("ls", "ls", "-l", (char *)NULL);
	printf("child process end\n");
	return (0);
}
