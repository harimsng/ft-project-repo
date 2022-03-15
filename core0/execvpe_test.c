#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_execvpe(const char *filename, char **argv, char **envp);

int	main(void)
{
	char	*argv_test[] = {"cat", "-e", "ft_memcpy.c", NULL};
	char	*envp_test[] = {NULL};

	if (fork() == 0)
	{
		printf("execve\n");
		execve("/usr/bin/cat", argv_test, envp_test);
	}
	wait(NULL);
	printf("\bft_execvpe\n");
	ft_execvpe("cat", argv_test, envp_test);
}
