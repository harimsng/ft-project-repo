#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#include "include/libft.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	char	**fork_argv;
	char	**envp_arr;
	char	**path_arr;
	char	filename[100];
	int		ret;

	if (argc < 2)
		return (0);
	fork_argv = malloc((argc + 1) * sizeof(char *));
	fork_argv[argc] = NULL;
	fork_argv[0] = strdup(argv[1]);
	for (int i = 2; i < argc; ++i)
		fork_argv[i - 1] = strdup(argv[i]);
	envp_arr = envp;
	while(*envp_arr)
	{
		if (strncmp(*envp_arr, "PATH=", 5) == 0)
			break;
		++envp_arr;
	}
	path_arr = ft_split((*envp_arr) + 5, ':');
	ret = -1;
	if ((pid = fork()) == 0)
	{
		for (int i = 0; path_arr[i] != NULL && ret != 0; ++i)
		{
			strlcpy(filename, path_arr[i], 100);
			strlcat(filename, "/", 100);
			strlcat(filename, fork_argv[0], 100);
			ret = execve(filename, fork_argv, envp);
		}
		perror(NULL);
	}
	else
		waitpid(pid, NULL, 0);
}
