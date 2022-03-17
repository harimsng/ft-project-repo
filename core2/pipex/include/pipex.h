/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:53:53 by hseong            #+#    #+#             */
/*   Updated: 2022/03/17 14:35:43 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE (1)
# define FALSE (0)

typedef int		t_bool;

typedef struct s_proc_info
{
	char	*filename;
	char	**argv;
	char	**envp;
	int		in_fd;
	int		out_fd;
	pid_t	pid;
}		t_proc_info;

typedef struct s_cmd_info
{
	int		argc;
	char	**argv;
	int		cmd_num;
	int		pipe_num;
	int		*pipe_arr;
	int		io_fd[2];
	t_bool	heredoc;
}		t_cmd_info;

// libft utility
void	*ft_memset(void *addr, int c, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_execvpe(const char *filename, char *const *argv, char *const *envp);
char	**ft_split(char *str, char delim);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

// initialization
t_bool	check_args(int argc, char **argv, t_cmd_info *cmd_info);
t_bool	set_io_files(t_cmd_info *cmd_info, int *io_fd);
void	make_pipe_arr(t_cmd_info *cmd_info);

// generate processes
void	gen_process(t_proc_info *proc_info, t_cmd_info *cmd_info);
void	set_proc_info(t_proc_info *proc_info,
			t_cmd_info *cmd_info, char **cmds);

// heredoc
void	pipex_heredoc(int *io_fd, char *limiter);

#endif
