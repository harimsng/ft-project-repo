/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:53:53 by hseong            #+#    #+#             */
/*   Updated: 2022/03/15 20:09:50 by hseong           ###   ########.fr       */
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
# define FALSE (0);

typedef int		t_bool;

typedef struct
{
	char	*filename;
	char	**argv;
	char	**envp;
	int		in_fd;
	int		out_fd;
	pid_t	pid;
}		t_process_info;

typedef struct
{
	int		argc;
	char	**argv;
	int		cmd_num;
	int		pipe_num;
	int		*pipe_arr;
	int		io_fd[2];
	t_bool	here_doc;
}		t_cmd_info;

int		ft_strcmp(const char *a, const char *b);
int		ft_execvpe(const char *filename, char *const *argv, char *const *envp);
char	**ft_split(char *str, char delim);
void	set_proc_info(t_process_info *proc_info,
			t_cmd_info *cmd_info, char **cmds);

#endif
