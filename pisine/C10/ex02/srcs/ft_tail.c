/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:24:20 by hseong            #+#    #+#             */
/*   Updated: 2021/10/26 18:59:11 by hseong           ###   ########.fr       */
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

int	get_files(char **argv, int buf_size);
int	print_files(int fd, int buf_size);

int	main(int argc, char **argv)
{
	int		buf_size;

	if (argc < 3)
	{
		ft_putstr("option requires an argument -- c\n");
		return (0);
	}
	buf_size = ft_stoi(argv[2]);
	if (argc == 3)
	{
		print_files(0);
		return (0);
	}
	else if (argc > 3)
		get_files(argv + 2);
	return (0);
}

int	get_files(char **argv, int buf_size)
{
	
}

int	print_files(int fd, int buf_size)
{
	int		read_size;
	char	*buf;
	char	*buf2;

	buf = (char *)malloc(sizeof(char) * buf_size);
	buf2 = (char *)malloc(sizeof(char) * buf_size);
	read_size = read(fd, buf, buf_size);
	while (read_size > buf_size)
	{
		strcpy(buf2, buf);
		read_size = read(fd, buf, buf_size);
	}
}
