/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:00:17 by hseong            #+#    #+#             */
/*   Updated: 2022/05/08 04:30:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_const.h"
#include "libft.h"
#include <readline/readline.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/wait.h>
# include <stdio.h>

int	main(void)
{
	t_token_arr	token_arr;
	char		*input_str;
	int			pid;
	int			execve_ret;
	int			state;

	input_str = readline("$> ");
	while (input_str != NULL)
	{
		token_arr = ft_split(input_str, " \t\n");
		pid = fork();
		if (pid == 0)
		{
			execve_ret = execvp(token_arr[0], token_arr);
			minishell_free_token(&token_arr);
			if (execve_ret == -1)
				ft_putendl_fd(strerror(errno), 2);
			return (errno);
		}
		minishell_free_token(&token_arr);
		waitpid(pid, &state, 0);
		input_str = readline("$> ");
	}
	return (0);
}
