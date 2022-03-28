/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:58:01 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 16:11:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

typedef char	**t_word_arr;

static t_bool	get_variable(int argc, char **var, t_map_info *map_info);
static t_bool	read_map(int fd, t_map_info *map_info);
static t_bool	check_map(t_map_info *map_info, t_word_arr *row_words);
static t_bool	dealloc_map(t_word_arr *row_words, t_bool error);

t_bool	fdf_load_map(int argc, char **argv, t_map_info *map_info)
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
	result = read_map(fd, map_info);
	result = result && get_variable(argc, argv + 2, map_info);
	map_info->max_height = get_z_coord(NULL);
	map_info->colored = get_color(NULL);
	return (result);
}

t_bool	get_variable(int argc, char **var, t_map_info *map_info)
{
	double	temp_hor_scale;

	fdf_align_map(map_info);
	if (argc == 4)
	{
		temp_hor_scale = (double)ft_atoi(var[0]);
		if (temp_hor_scale != 0)
			map_info->hor_scale = temp_hor_scale;
		map_info->ver_scale = (double)ft_atoi(var[1]);
	}
	return (TRUE);
}

t_bool	read_map(int fd, t_map_info *map_info)
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
	map_info->row = idx;
	map_info->map_origin = malloc(sizeof(t_vertex *) * map_info->row);
	return (check_map(map_info, row_words));
}

t_bool	check_map(t_map_info *map_info, t_word_arr *row_words)
{
	int		idx;
	int		jdx;

	idx = 0;
	map_info->colored = FALSE;
	while (row_words[0][idx] != NULL)
		++idx;
	map_info->col = idx;
	idx = 0;
	while (idx < map_info->row)
	{
		map_info->map_origin[idx] = malloc(sizeof(t_vertex) * map_info->col);
		jdx = 0;
		while (row_words[idx][jdx] != NULL && jdx < map_info->col)
		{
			map_info->map_origin[idx][jdx] = (t_vertex){.y = idx, .x = jdx,
				.z = get_z_coord(row_words[idx][jdx]),
				.color = get_color(row_words[idx][jdx])};
			++jdx;
		}
		if (jdx != map_info->col)
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
