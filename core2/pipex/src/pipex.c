/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:51:36 by hseong            #+#    #+#             */
/*   Updated: 2022/03/15 20:17:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_bool	check_args(int argc, char **argv, t_cmd_info *cmd_info);
static t_bool	set_io_files(t_cmd_info *cmd_info, int *io_fd);
static void		make_pipe_arr(t_cmd_info *cmd_info);

static const char	*nullptr = NULL;

int	main(int argc, char *argv[])
{
	t_process_info	*proc_info;
	t_cmd_info		cmd_info;

	cmd_info = (t_cmd_info){argc, argv, 0, 0, NULL, {0, 0}, 0};
	if (set_io_files(&cmd_info, io_fd) == FALSE
		|| check_args(argc, argv, &cmd_info) == FALSE)
		exit(1);
	proc_info = malloc(sizeof(t_process_info) * cmd_info.cmd_num);
	ft_memset(proc_info, 0, sizeof(t_process_info) * cmd_info.cmd_num);
	set_proc_info(proc_info, &cmd_info, argv + 2 + cmd_info.here_doc);
	gen_proc(proc_info, &cmd_info);
	free_info(proc_info, &cmd_info);
	return (0);
}

t_bool	check_args(int argc, char **argv, t_cmd_info *cmd_info)
{
	cmd_info->here_doc = ft_strcmp(argv[1], "here_doc") == 0;
	if (argc < 5 + cmd_info->here_doc)
	{
		write(2, "Invalid arguments.\n", 19);
		return (FALSE);
	}
	cmd_info->cmd_num = argc - 3 - cmd_info->here_doc;
	cmd_info->pipe_num = cmd_info->cmd_num - 1;
	cmd_info->pipe_arr = malloc(sizeof(int) 2 * * cmd_info->pipe_num);//will this work?[
	make_pipe_arr(cmd_info);
	return (TRUE);
}

t_bool	set_io_files(t_cmd_info *cmd_info, int *io_fd)
{
	int		*io_fd;

	io_fd = cmd_info->io_fd;
	if (cmd_info->here_doc == FALSE)
	{
		if (access(argv[1], R_OK) == -1)
		{
			perror("Input file is invalid\n");
			return (FALSE);
		}
		io_fd[0] = open(argv[1], O_RDONLY);
	}
	io_fd[1] = open(argv[cmd_info->argc - 1], O_CREAT | O_WRONLY, 0444);
	if (io_fd[0] == -1 || io_fd[1] == -1)
	{
		perror(NULL);
		return (FALSE);
	}
	return (TRUE);
}

void	make_pipe_arr(t_cmd_info *cmd_info)
{
	size_t		idx;
	size_t		size;
	int			*pipe_arr;
	int			flag;

	idx = 0;
	size = cmd_info->pipe_num;
	pipe_arr = cmd_info->pipe_arr;
	while (idx < size && flag != -1)
	{
		flag = pipe(pipe_arr + 2 * idx);
		++idx;
	}
	if (flag == -1)
		perror("pipe error");
}
