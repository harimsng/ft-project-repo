/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:16:41 by hseong            #+#    #+#             */
/*   Updated: 2022/06/07 15:51:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_bool	check_args(int argc, char **argv, t_cmd_info *cmd_info)
{
	cmd_info->heredoc = ft_strncmp(argv[argc != 1], "heredoc", 8) == 0;
	if (argc < 5 + cmd_info->heredoc)
	{
		write(2, "Invalid arguments.\n", 19);
		return (FALSE);
	}
	cmd_info->cmd_num = argc - 3 - cmd_info->heredoc;
	cmd_info->pipe_num = cmd_info->cmd_num - 1;
	cmd_info->pipe_arr = malloc(sizeof(int) * 2 * cmd_info->pipe_num);
	make_pipe_arr(cmd_info);
	return (cmd_info->pipe_arr != NULL);
}

t_bool	set_io_files(t_cmd_info *cmd_info, int *io_fd)
{
	io_fd = cmd_info->io_fd;
	if (cmd_info->heredoc == FALSE)
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
	else
		io_fd[0] = 0;
	io_fd[1] = open(cmd_info->argv[cmd_info->argc - 1],
			(O_APPEND * cmd_info->heredoc)
			| (O_TRUNC * !cmd_info->heredoc)
			| O_CREAT | O_WRONLY, 0666);
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
