/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:58:01 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 21:16:25 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>

typedef char	**t_word_arr;

static t_bool	get_variable(int argc, char **var, t_map_info *map_info);
static t_bool	read_map(int fd, t_map_info *map_info);
static t_bool	check_map(t_map_info *map_info, t_word_arr *row_words);
static t_bool	dealloc_map(t_word_arr *row_words, t_bool error);

t_bool	fdf_load_map(int argc, char **argv, t_map_info *map_info)
{
	t_bool	flag1;
	int		fd;

	ft_putstr_fd("loading map file\n", 1);
	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd("./fdf map_name [width unit] [height unit]", 2);
		exit(0x4);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Invalid map file");
		exit(0x8);
	}
	flag1 = read_map(fd, map_info);
	if (flag1)
		get_variable(argc, argv + 2, map_info);
	map_info->max_height = get_z_coord(NULL);
	map_info->colored = get_color(NULL);
	return (flag1);
}

t_bool	get_variable(int argc, char **var, t_map_info *map_info)
{
	double	temp_hor_scale;

	fdf_setup_map(map_info);
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
	map_info->colored = FALSE;
	map_info->row = idx;
	map_info->map_origin = malloc(sizeof(t_vertex *) * map_info->row);
	map_info->carry = NULL;
	return (check_map(map_info, row_words));
}

t_bool	check_map(t_map_info *map_info, t_word_arr *row_words)
{
	int		idx;
	int		jdx;

	idx = 0;
	while (row_words[0][idx] != NULL)
		++idx;
	map_info->col = idx;
	idx = 0;
	jdx = map_info->col;
	while (idx < map_info->row && jdx == map_info->col)
	{
		map_info->map_origin[idx] = malloc(sizeof(t_vertex) * map_info->col);
		jdx = 0;
		while (row_words[idx][jdx] != NULL && jdx < map_info->col)
		{
			map_info->map_origin[idx][jdx] = (t_vertex){
				.y = idx - map_info->row / 2,
				.x = jdx - map_info->col / 2,
				.z = get_z_coord(row_words[idx][jdx]),
				.color = get_color(row_words[idx][jdx])};
			++jdx;
		}
		++idx;
	}
	return (dealloc_map(row_words, jdx != map_info->col));
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
