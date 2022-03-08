#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

int	main(void)
{
	if (fork() == 0)
	{
		printf("child process created\n");
		sleep(1);
		execlp("ls", "ls", "-l", NULL);
		printf("child process end\n");
		return (0);
	}
	printf("waiting child process to terminate\n");
	wait(NULL);
	printf("wating ends\n");
	return (0);
}
