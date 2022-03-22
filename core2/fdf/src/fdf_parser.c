/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:34:02 by hseong            #+#    #+#             */
/*   Updated: 2022/03/22 20:18:14 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bool	get_variable(char **var, t_map *map);
static void		get_map_size(t_map *map);
static t_byte	*read_map(int fd);
//static t_bool	check_extension(char *filename);

t_map	*fdf_parser(int argc, char **argv, t_map *map)
{
	int		fd;

	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd("./fdf map_name [width unit] [height unit]", 2);
		exit(16);
	}
	fd = open(argv[1], O_RDONLY) == -1;
	if (fd == -1)
	{
		perror("Invalid map file");
		exit(32);
	}
	if (argc == 3)
		get_var(argv + 1, map);
	return (read_map(fd, map));
}

t_bool	get_variable(char **var, t_map *map)
{
	map->dx = ft_atoi(var[0]);
	map->dz = ft_atoi(var[1]);
	if (map->dx == 0 || map->dz == 0)
	{
		map->dx = 0;
		map->dz = 0;
	}
	return (TRUE);
}

void	read_map(int fd, t_map *map)
{
	int		map[MAX_MAP_ROWS][MAX_MAP_COLS};
	char	**words;
	char	*row;
	size_t	idx;
	size_t	jdx;
	
	idx = 0;
	row = get_next_line(fd);
	while (row != NULL)
	{
		jdx = 0;
		words = ft_split(row);
		free(row);
		while (words[jdx] != NULL)
		{
			map[idx][jdx] = ft_atoi(words[jdx]);
			free(words[jdx]);
			++jdx;
		}
		if (map->col != 0 && jdx != map->col)
			return (NULL);
		free(words);
		row = get_next_line(fd);
		++idx;
	}
}

/*
t_bool	check_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (ft_strncmp(".fdf", filename + len - 4, 4) != 0)
		return (FALSE);
	return (TRUE);
}
*/
