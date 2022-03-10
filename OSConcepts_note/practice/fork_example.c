#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	if (fork() == 0)
		printf("this is child process. %d\n", getpid());
	else
		printf("parent process %d\n", getpid());
	return (0);
}
