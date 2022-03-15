/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:01:25 by hseong            #+#    #+#             */
/*   Updated: 2022/03/15 20:17:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	gen_proc(t_process_info *proc_info, t_cmd_info *cmd_info)
{
	size_t			idx;
	size_t			size;
	int				temp_pid;
	t_process_info	*proc;

	idx = 0;
	size = cmd_info->cmd_num;
	while (idx < size)
	{
		proc = proc_info + idx;
		proc->pid = fork();
		if (temp_pid == 0)
			break ;
		++idx;
	}
	if (temp_pid == 0)
	{
		close_pipe(idx, cmd_info);
		ft_execvpe(proc->filename, proc->argv, proc->envp);
		perror("execve failed");
	}
	else
		wait_childs(proc_info, cmd_info);
}

void	set_proc_info(t_process_info *proc_info,
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
		proc_info[idx] = (t_process_info) {
			.argv = ft_split(cmds[idx], ' '),
			.envp = proc_info[idx].argv[0],
			.in_fd = (idx > 0) * pipe_arr[2 * idx - 1],
			.out_fd = (idx < size - 1) * pipe_arr[2 * idx],
			.pid = 0
		};
//		proc_info[idx].filename = proc_info[idx].argv[0];
		++idx;
	}
	proc_info[0].in_fd = cmd_info->io_fd[0];
	proc_info[idx - 1].out_fd = cmd_info->io_fd[1];
}
