/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:16:41 by hseong            #+#    #+#             */
/*   Updated: 2022/03/16 19:10:24 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	check_args(int argc, char **argv, t_cmd_info *cmd_info)
{
	cmd_info->here_doc = ft_strncmp(argv[argc != 1], "here_doc", 8) == 0;
	if (argc < 5)
	{
		write(2, "Invalid arguments.\n", 19);
		return (FALSE);
	}
	cmd_info->cmd_num = argc - 3 - cmd_info->here_doc;
	cmd_info->pipe_num = cmd_info->cmd_num - 1;
	cmd_info->pipe_arr = malloc(sizeof(int) * 2 * cmd_info->pipe_num);
	make_pipe_arr(cmd_info);
	return (cmd_info->pipe_arr != NULL);
}

t_bool	set_io_files(t_cmd_info *cmd_info, int *io_fd)
{
	io_fd = cmd_info->io_fd;
	if (cmd_info->here_doc == FALSE)
	{
		if (access(cmd_info->argv[1], R_OK) == -1)
		{
			perror("Input file is invalid");
			return (FALSE);
		}
		io_fd[0] = open(cmd_info->argv[1], O_RDONLY);
		if (io_fd[0] == -1)
			perror("Failed to open input file");
	}
	io_fd[1] = open(cmd_info->argv[cmd_info->argc - 1],
			O_CREAT | O_TRUNC | O_WRONLY, 0666);
	if (io_fd[1] == -1)
	{
		perror("Failed to open output file");
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
	flag = 0;
	while (idx < size && flag != -1)
	{
		flag = pipe(pipe_arr + 2 * idx);
		++idx;
	}
	if (flag == -1)
		perror("pipe error");
}
