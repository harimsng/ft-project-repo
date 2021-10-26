/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:24:20 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 01:56:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

// option requires an argument	ex) $> tail -c
// illegal offset				ex) $> tail -c a
// standard input				ex) $> tail -c 5
// multiple input				ex) $> tail -c 3 test test2
// 									==> test <==
// 									...
//
// 									==> test2 <==
// No such file or directory	ex) $> tail -c 5 nonexist

static const char	*prog_name = "tail: ";

int					arg_check(int argc, char **argv);
void				get_files(char **argv, int buf_size);
void				print_files(int fd, int buf_size);
void				error_msg(char *str);

int	main(int argc, char **argv)
{
	int		buf_size;

	if (arg_check(argc, argv))
		return (0);
	buf_size = ft_stoi(argv[2]);
	if (argc == 3)
	{
		print_files(0, buf_size);
		return (0);
	}
	else if (argc > 3)
		get_files(argv + 3, buf_size);
	return (0);
}

int	arg_check(int argc, char **argv)
{
	if (argc < 3)
	{
		ft_puterr(prog_name);
		ft_puterr("option requires an argument -- c\n");
		return (1);
	}
	else if (!ft_str_is_numeric(argv[2])) 
	{
		ft_puterr(prog_name);
		ft_puterr("illegal offset -- ");
		ft_puterr(argv[3]);
		ft_puterr("\n");
		return (1);
	}
	return (0);
}

void	get_files(char **argv, int buf_size)
{
	int		fd;
	int		multiple_file;

	multiple_file = 0;
	if (*(argv + 1) != 0)
		multiple_file = 1;
	while (*argv)
	{
		fd = open(*argv, O_RDONLY);
		if (fd < 0)
			error_msg(*argv);
		else
		{
			if (multiple_file++)
			{
				if (multiple_file > 2)
					ft_putstr("\n");
				ft_putstr("==> ");
				ft_putstr(*argv);
				ft_putstr(" <==\n");
			}
			print_files(fd, buf_size);
		}
		++argv;
	}
}

void	print_files(int fd, int buf_size)
{
	int		read_size;
	char	*buf;
	char	*buf2;

	buf = (char *)malloc(sizeof(char) * (buf_size + 1));
	buf2 = (char *)malloc(sizeof(char) * (buf_size + 1));
	read_size = read(fd, buf, buf_size);
	while (read_size >= buf_size)
	{
		ft_strlcpy(buf2, buf, buf_size + 1);
		read_size = read(fd, buf, buf_size);
	}
	if (read_size < 0)
	{
		error_msg(0);
		return ;
	}
	write(1, buf2 + read_size, buf_size - read_size);
	write(1, buf, read_size);	
}

void	error_msg(char *str)
{
	ft_puterr(prog_name);
	if (str)
	{
		ft_puterr(str);
		ft_puterr(": ");
	}
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}
