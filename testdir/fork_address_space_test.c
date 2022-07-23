#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

static int	child_work(int *target_ptr);

int	main(void)
{
	int		target = 42;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		return (child_work(&target));
	pid = fork();
	if (pid == 0)
		return (child_work(&target));
	wait(NULL);
	wait(NULL);
	return (0);
}

int	child_work(int *target_ptr)
{
	printf("ptr = %p\n", target_ptr);
	return (0);
}
