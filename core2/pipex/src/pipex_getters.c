/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:18:25 by hseong            #+#    #+#             */
/*   Updated: 2022/03/15 15:52:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**get_pipe_arr(size_t pipes)
{
	int		**pipe_arr;
	size_t	idx;

	pipe_arr = malloc(sizeof(int *) * pipes);
	idx = 0;
	while (idx < pipes)
	{
		pipe_arr[idx] = malloc(sizeof(int) * 2);
		++idx;
	}
	return (pipe_arr);
}

int	*get_pid_arr(size_t cmds)
{
	return (malloc(sizeof(int) * cmds));
}

char	**get_arg_arr(char **argv, size_t cmds, t_bool here_doc)
{
	
}
