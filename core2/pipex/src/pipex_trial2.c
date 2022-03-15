/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:38:52 by hseong            #+#    #+#             */
/*   Updated: 2022/03/15 15:16:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static const char	*nullptr = NULL;

static int	arg_check(int argc, char **argv);
static int	process_setup(int argc, char **argv, size_t pipes, t_bool here_doc);

int	main(int argc, char *argv[])
{
	size_t	cmd_count;
	t_bool	here_doc;

	cmd_count = arg_check(argc, argv);
	here_doc = FALSE;
	if (cmd_count == 0)
	{
		write(2, "Invalid arguments\n", 18);
		return (0);
	}
	else if (argc - cmd_count == 4)
		here_doc = TRUE;
	if (process_setup(argc, argv + 1, cmd_count - 1, here_doc) == FALSE)
		perror(NULL);
	return (0);
}

int	arg_check(int argc, char **argv)
{
	t_bool	here_doc;

	here_doc = ft_strcmp(srgv[1], "here_doc") == 0;
	if (argc < 5 + here_doc)
		return (0);
	return (argc - 3 - here_doc);
}

int	process_setup(int argc, char **argv, size_t pipes, t_bool here_doc)
{
	size_t	idx;
	char	**arg_arr;
	char	**each_argv;
	int		**pipe_arr;
	int		*pid_arr;
	int		temp_stdio[2];
	int		iofile_fd[2];

	iofile_fd[0] = open(argv[1], O_CREAT | O_WRONLY, 0777);
	iofile_fd[1] = open(argv[argc - 1], O_RDONLY);
	if (iofile_fd[0] == -1 || iofile_fd[1] == -1)
	{
		perror(NULL);
		exit(1);
	}
	temp_stdio[0] = dup(0);
	temp_stdio[1] = dup(1);
	pipe_arr = get_pipe_arr(pipes);
	pid_arr = get_pid_arr(pipes + 1);
	arg_arr = get_arg_arr(argv, pipes + 1, here_doc);
	idx = 0;
	while (idx < pipes + 1)
	{
		pid_arr[idx] = fork();
		if (pid_arr[idx] == 0)
			break ;
		++idx;
	}
	close_pipe_arr(pipe_arr, pipes, idx);
	if (idx == 0)
		dup2(iofile_fd[0], 0);
	else	
		dup2(pipe_arr[idx - 1][1], 0);
	if (idx == pipes)
		dup2(iofile_fd[1], 1);
	else
		dup2(pipe_arr[idx][0], 1);
	each_argv = get_argv(arg_arr[idx]);
	if (pid_arr[idx] == 0)
	{
		if (execve(each_argv[0], each_argv, &nullptr) == -1)
		{
			perror(NULL);
			exit(1);
		}
	}
	free_pipe_arr(pipe_arr, pipes);
}
