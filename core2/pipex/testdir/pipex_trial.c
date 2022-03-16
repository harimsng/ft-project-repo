/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_trial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:38:47 by hseong            #+#    #+#             */
/*   Updated: 2022/03/15 13:38:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_argv(char *arg);
char	**get_env(void);

int	main(int argc, char *argv[])
{
	int		input_fd;
	int		output_fd;
	int		pipe_fd[2];
	int		child_pid;
	int		execute_ret;
//	char	*new_argv[] = {"/usr/bin/cat", NULL};
//	char	*new_env[] = {NULL};

	if (argc < 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (0);
	}
	printf("argv: %s %s %s %s\n", argv[1], argv[2], argv[3], argv[4]);
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		perror(__func__);
//	temp_stdout = dup(1);
//	temp_stdin = dup(0);
	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (output_fd == -1)
		perror(__func__);
//	pipe_fd[1] = temp_stdin;
//	pipe_fd[0] = temp_stdout;
	if (pipe(pipe_fd) == -1)
		perror(__func__);
	child_pid = fork();
	if (child_pid == -1)
		perror(__func__);
	else if (child_pid != 0)
	{
		close(pipe_fd[1]);
		dup2(output_fd, 1);
		dup2(pipe_fd[0], 0);
		wait(NULL);
		execute_ret = execve(argv[3], get_argv(argv[3]), get_env());
		if (execute_ret == -1)
			perror(__func__);
	}
	else
	{
		close(pipe_fd[0]);
		dup2(input_fd, 0);
		dup2(pipe_fd[1], 1);
		execute_ret = execve(argv[2], get_argv(argv[2]), get_env());
		if (execute_ret == -1)
			perror(__func__);
	}
	return (0);
}

char	**get_argv(char *arg)
{
	char	**argv = malloc(sizeof(char *) * 2);

	argv[0] = arg;
	argv[1] = NULL;
	return (argv);
}

char	**get_env(void)
{
	char	**env = malloc(sizeof(char *));

	env[0] = NULL;
	return (env);
}
