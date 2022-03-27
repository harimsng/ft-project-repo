/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:58:01 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 18:19:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

typedef char	**t_word_arr;

static t_bool	get_variable(int argc, char **var, t_map *map);
static t_bool	read_map(int fd, t_map *map);
static t_bool	check_map(t_map *map, t_word_arr *row_words);
static t_bool	dealloc_map(t_word_arr *row_words, t_bool error);

t_bool	fdf_load_map(int argc, char **argv, t_map *map)
{
	t_bool	result;
	int		fd;

	ft_putstr_fd("loading map file...\n", 1);
	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd("./fdf map_name [width unit] [height unit]", 2);
		exit(16);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Invalid map file");
		exit(32);
	}
	result = read_map(fd, map);
	result = result && get_variable(argc, argv + 2, map);
	map->max_height = get_z_coord(NULL);
	map->colored = get_color(NULL);
	return (result);
}

t_bool	get_variable(int argc, char **var, t_map *map)
{
	double	temp_hor_scale;

	fdf_align_map(map);
	if (argc == 4)
	{
		temp_hor_scale = (double)ft_atoi(var[0]);
		if (temp_hor_scale != 0)
			map->hor_scale = temp_hor_scale;
		map->ver_scale  = (double)ft_atoi(var[1]);
	}
	return (TRUE);
}

t_bool	read_map(int fd, t_map *map)
{
	char		*raw_row;
	t_word_arr	row_words[MAP_MAXROWS];
	size_t		idx;

	raw_row = get_next_line(fd);
	idx = 0;
	while (raw_row != NULL)
	{
		row_words[idx] = ft_split(raw_row, "\n\t ");
		free(raw_row);
		raw_row = get_next_line(fd);
		++idx;
	}
	row_words[idx] = NULL;
	map->row = idx;
	map->map_arr = malloc(sizeof(t_vertex *) * map->row);
	return (check_map(map, row_words));
}

t_bool	check_map(t_map *map, t_word_arr *row_words)
{
	int		idx;
	int		jdx;

	idx = 0;
	map->colored = FALSE;
	while (row_words[0][idx] != NULL)
		++idx;
	map->col = idx;
	idx = 0;
	while (idx < map->row)
	{
		map->map_arr[idx] = malloc(sizeof(t_vertex) * map->col);
		jdx = 0;
		while (row_words[idx][jdx] != NULL && jdx < map->col)
		{
			map->map_arr[idx][jdx] = (t_vertex){.y = idx, .x = jdx,
				.z = get_z_coord(row_words[idx][jdx]),
				.color = get_color(row_words[idx][jdx])};
			++jdx;
		}
		if (jdx != map->col)
			return (dealloc_map(row_words, TRUE));
		++idx;
	}
	return (dealloc_map(row_words, FALSE));
}

t_bool	dealloc_map(t_word_arr *row_words, t_bool error)
{
	size_t		idx;

	while (*row_words)
	{
		idx = 0;
		while (row_words[0][idx])
			free(row_words[0][idx++]);
		free(*row_words);
		++row_words;
	}
	if (error)
		return (FALSE);
	return (TRUE);
}
