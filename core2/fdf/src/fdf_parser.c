/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:34:02 by hseong            #+#    #+#             */
/*   Updated: 2022/03/20 20:30:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bool	get_var(char **var, t_mlxinfo *mlxinfo);
static t_byte	*readfile(int fd);

t_byte	*fdf_parser(int argc, char **argv, t_mlxinfo *mlxinfo)
{
	int		fd;
	if (argc > 3)
		return (FALSE);
	if (argc == 3)
		get_var(argv + 1, mlxinfo);
	fd = open(argv[1], O_RDONLY) == -1;
	if (fd == -1)
	{
		perror("Invalid map file");
		exit (16);
	}
	return (readfile(fd));
}

static t_bool	get_var(char **var, t_mlxinfo *mlxinfo)
{
	mlxinfo->hor_size = ft_atoi(var[0]);
	mlxinfo->ver_size = ft_atoi(var[1]);
	if (mlxinfo->hor_size == 0 || mlxinfo->ver_size == 0)
	{
		mlxinfo->hor_size = 0;
		mlxinfo->ver_size = 0;
	}
	return (TRUE);
}

static t_byte	*readfile(int fd)
{
	char	*str;
	char	**wordarr;
	char	**temp;
	int		**map;
	size_t	wordcount;

	str = get_next_line(fd);
	while (str)
	{
		wordarr = ft_split(str);
		temp = wordarr;
		wordcount = 0;
		while (temp)
		{
			*temp = get_point(temp);
			++temp;
			++wordcount;
		}
		free(str);
		str = get_next_line(fd);
	}
	return (wordarr);
}
