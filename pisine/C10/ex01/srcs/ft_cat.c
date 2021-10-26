/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:24:12 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 00:51:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

#define BUF_LEN 30000

static const char	*prog_name = "cat: ";

int					print_file(int fd);
int					get_files(char **argv);
void				error_check(int num, char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		error_check(print_file(0), 0);
	else
		get_files(argv + 1);
	return (0);
}

int	print_file(int fd)
{
	char		buf[BUF_LEN + 1];
	int			read_size;

	read_size = read(fd, buf, BUF_LEN);
	while (read_size > 0)
	{
		write(1, buf, read_size);
		read_size = read(fd, buf, BUF_LEN);
	}
	if (read_size < 0)
		return (1);
	return (0);
}

int	get_files(char **argv)
{
	int			fd;

	while (*argv)
	{
		if ((*argv)[0] == '-' && (*argv)[1] == 0)
			print_file(0);
		else
		{
			fd = open(*argv, O_RDONLY);
			if (fd < 0 || print_file(fd))
				error_check(1, *argv);
		}
		++argv;
	}
	return (0);
}

void	error_check(int num, char *str)
{
	if (num == 0)
		return ;
	ft_puterr(prog_name);
	if (str)
	{
		ft_puterr(str);
		ft_puterr(": ");
	}
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}
