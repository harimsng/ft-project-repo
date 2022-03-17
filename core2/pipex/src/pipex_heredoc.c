/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:29:39 by hseong            #+#    #+#             */
/*   Updated: 2022/03/17 16:29:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_next_line(int fd);

void	pipex_heredoc(int *in_fd, char *limiter)
{
	int		pipe_fd[2];
	char	*bufptr;
	size_t	lim_len;

	pipe(pipe_fd);
	*in_fd = pipe_fd[0];
	lim_len = ft_strlen(limiter);
	write(1, "> ", 2);
	bufptr = get_next_line(0);
	while (bufptr == NULL
		|| ft_strncmp(bufptr, limiter, lim_len) != 0
		|| bufptr[lim_len] != '\n')
	{
		write(pipe_fd[1], bufptr, ft_strlen(bufptr));
		if (bufptr != NULL)
			free(bufptr);
		write(1, "> ", 2);
		bufptr = get_next_line(0);
	}
	free(bufptr);
	close(pipe_fd[1]);
}
