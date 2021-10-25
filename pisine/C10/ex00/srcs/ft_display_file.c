/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:24:08 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 17:26:13 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

#define BUF_LEN 256

int		argc_check(int argc);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int		fd;
	int		read_num;
	char	buf[BUF_LEN + 1];

	if (argc_check(argc))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (0);
	}
	read_num = read(fd, buf, BUF_LEN);
	while (read_num > 0)
	{
		buf[read_num] = 0;
		ft_putstr(buf);
		read_num = read(fd, buf, BUF_LEN);
	}
	close(fd);
	return (0);
}

int	argc_check(int argc)
{
	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	return (0);
}
