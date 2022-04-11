/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:58:01 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 16:20:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef char	**t_word_arr;

static t_bool	get_variable(int argc, char **var, t_map_info *map_info);
static t_bool	read_map(int fd, t_map_info *map_info);
static t_bool	check_map(t_map_info *map_info, t_word_arr *words);
static void		dealloc_words(t_word_arr *words);

t_bool	fdf_load_map(int argc, char **argv, t_map_info *map_info)
{
	t_bool		flag1;
	int			fd;

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
	map_info->colored_flag = get_color(NULL);
	return (flag1);
}

t_bool	get_variable(int argc, char **var, t_map_info *map_info)
{
	double	temp_hor_scale;

	if (argc == 4)
	{
		temp_hor_scale = (double)ft_atoi(var[0]);
		if (temp_hor_scale != 0)
			map_info->hor_scale = temp_hor_scale;
		map_info->ver_scale = (double)ft_atoi(var[1]);
		map_info->arg_flag = TRUE;
	}
	return (TRUE);
}

t_bool	read_map(int fd, t_map_info *map_info)
{
	char		*line;
	t_word_arr	words[MAP_MAXROWS + 1];
	size_t		idx;

	line = get_next_line(fd);
	if (line == NULL)
		return (FALSE);
	idx = 0;
	while (line != NULL)
	{
		words[idx] = ft_split(line, "\n\t ");
		free(line);
		line = get_next_line(fd);
		++idx;
	}
	words[idx] = NULL;
	map_info->row = idx;
	map_info->map_origin = malloc(sizeof(t_vertex *) * map_info->row);
	if (map_info->map_origin == NULL)
		return (FALSE);
	return (check_map(map_info, words));
}

t_bool	check_map(t_map_info *map_info, t_word_arr *words)
{
	int		idx;
	int		jdx;

	jdx = 0;
	while (words[0][jdx] != NULL)
		++jdx;
	idx = 0;
	map_info->col = jdx;
	while (idx < map_info->row && jdx == map_info->col)
	{
		map_info->map_origin[idx] = malloc(sizeof(t_vertex) * map_info->col);
		jdx = 0;
		while (words[idx][jdx] != NULL && jdx < map_info->col)
		{
			map_info->map_origin[idx][jdx] = (t_vertex){
				.y = idx - map_info->row / 2, .x = jdx - map_info->col / 2,
				.z = get_z_coord(words[idx][jdx]),
				.color = get_color(words[idx][jdx])};
			++jdx;
		}
		++idx;
	}
	map_info->row = idx;
	dealloc_words(words);
	return (jdx == map_info->col);
}

void	dealloc_words(t_word_arr *words)
{
	size_t		idx;

	while (*words)
	{
		idx = 0;
		while (words[0][idx])
			free(words[0][idx++]);
		free(*words);
		++words;
	}
}
