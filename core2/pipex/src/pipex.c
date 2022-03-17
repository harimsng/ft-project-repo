/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:51:36 by hseong            #+#    #+#             */
/*   Updated: 2022/03/17 16:18:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_fd(t_cmd_info *cmd_info);
static void	dealloc_info(t_proc_info *proc_info, t_cmd_info *cmd_info);
static void	dealloc_argv(char **argv);
static void	wait_child(t_proc_info *proc_info, t_cmd_info *cmd_info);

int	main(int argc, char *argv[])
{
	t_proc_info	*proc_info;
	t_cmd_info	cmd_info;

	cmd_info = (t_cmd_info){argc, argv, 0, 0, NULL, {0, 0}, 0};
	if (check_args(argc, argv, &cmd_info) == FALSE
		|| set_io_files(&cmd_info, cmd_info.io_fd) == FALSE)
		exit(1);
	proc_info = malloc(sizeof(t_proc_info) * cmd_info.cmd_num);
	if (proc_info == NULL)
		return (1);
	ft_memset(proc_info, 0, sizeof(t_proc_info) * cmd_info.cmd_num);
	set_proc_info(proc_info, &cmd_info, argv + 2 + cmd_info.heredoc);
	gen_process(proc_info, &cmd_info);
	close_fd(&cmd_info);
	wait_child(proc_info, &cmd_info);
	dealloc_info(proc_info, &cmd_info);
	return (0);
}

void	close_fd(t_cmd_info *cmd_info)
{
	size_t		idx;
	size_t		size;
	int			flag;

	idx = 0;
	size = 2 * cmd_info->pipe_num;
	while (idx < size && flag != -1)
	{
		flag = close(cmd_info->pipe_arr[idx]);
		++idx;
	}
	if (flag == -1
		|| close(cmd_info->io_fd[0]) == -1
		|| close(cmd_info->io_fd[1]) == -1)
		perror("FD close error");
}

void	dealloc_info(t_proc_info *proc_info, t_cmd_info *cmd_info)
{
	size_t		idx;
	size_t		size;

	idx = 0;
	size = cmd_info->cmd_num;
	while (idx < size)
	{
		dealloc_argv(proc_info[idx].argv);
		dealloc_argv(proc_info[idx].envp);
		++idx;
	}
	free(proc_info);
	free(cmd_info->pipe_arr);
}

void	dealloc_argv(char **argv)
{
	char	**temp;

	temp = argv;
	while (*argv)
	{
		free(*argv);
		++argv;
	}
	free(temp);
}

void	wait_child(t_proc_info *proc_info, t_cmd_info *cmd_info)
{
	size_t		idx;
	size_t		size;

	size = cmd_info->cmd_num;
	idx = 0;
	while (idx < size)
	{
		if (waitpid(proc_info[idx].pid, NULL, 0)
			!= proc_info[idx].pid)
			perror("waitpid() warning");
		++idx;
	}
}
