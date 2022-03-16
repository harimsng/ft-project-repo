/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:01:25 by hseong            #+#    #+#             */
/*   Updated: 2022/03/16 20:36:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	connect_pipe(t_proc_info *process);
static void	close_fd(size_t idx, t_proc_info *proc_info, t_cmd_info *cmd_info);

void	gen_process(t_proc_info *proc_info, t_cmd_info *cmd_info)
{
	size_t		idx;
	size_t		size;
	t_proc_info	*proc;

	idx = 0;
	size = cmd_info->cmd_num;
	while (idx < size)
	{
		proc = proc_info + idx;
		proc->pid = fork();
		if (proc->pid == 0)
			break ;
		++idx;
	}
	if (proc->pid == 0)
	{
		close_fd(idx, proc_info, cmd_info);
		connect_pipe(proc_info + idx);
		ft_execvpe(proc->filename, proc->argv, proc->envp);
		perror("execve failed");
		exit(1);
	}
}

void	set_proc_info(t_proc_info *proc_info,
					t_cmd_info *cmd_info, char **cmds)
{
	size_t		idx;
	size_t		size;
	int			*pipe_arr;

	idx = 0;
	size = cmd_info->cmd_num;
	pipe_arr = cmd_info->pipe_arr;
	while (idx < size)
	{
		proc_info[idx] = (t_proc_info){
			.argv = ft_split(cmds[idx], ' '),
			.envp = malloc(sizeof(char *)), .pid = 0};
		if (idx != 0 && idx != size - 1)
		{
			proc_info[idx].out_fd = pipe_arr[2 * idx + 1];
			proc_info[idx].in_fd = pipe_arr[2 * idx - 2];
		}
		proc_info[idx].envp[0] = NULL;
		proc_info[idx].filename = proc_info[idx].argv[0];
		++idx;
	}
	proc_info[0].in_fd = cmd_info->io_fd[0];
	proc_info[0].out_fd = pipe_arr[1];
	proc_info[idx - 1].in_fd = pipe_arr[2 * idx - 4];
	proc_info[idx - 1].out_fd = cmd_info->io_fd[1];
}

// idx is index of cmd. size is size of pipe_arr.
void	close_fd(size_t idx, t_proc_info *proc_info, t_cmd_info *cmd_info)
{
	size_t	jdx;
	size_t	size;
	int		flag;

	jdx = 0;
	size = cmd_info->cmd_num;
	flag = 0;
	while (jdx < size && flag != -1)
	{
		if (jdx != idx)
		{
			flag = close(proc_info[jdx].in_fd);
			if (flag == -1)
			{
				perror("FD close error");
				++jdx;
				continue ;
			}
			flag = close(proc_info[jdx].out_fd);
		}
		++jdx;
	}
	if (flag == -1)
		perror("FD close error");
}

void	connect_pipe(t_proc_info *process)
{
	if (dup2(process->in_fd, 0) == -1
		|| dup2(process->out_fd, 1) == -1)
		perror("dup2() failed");
}
