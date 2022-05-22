/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_load_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:58:01 by hseong            #+#    #+#             */
/*   Updated: 2022/05/22 21:41:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef char	**t_word_arr;

char			*get_next_line(int fd);
static int		read_map(int fd, t_map_info *map_info);
static int		check_map(t_map_info *map_info, t_word_arr *words);
static void		dealloc_words(t_word_arr *words);

int	c3d_load_map(int argc, char **argv, t_map_info *map_info)
{
	t_bool	flag1;
	int		fd;

	ft_putstr_fd("loading map file\n", 1);
	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd("arguments error\n", 2);
		exit(0x4);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Invalid map file");
		exit(0x8);
	}
	flag1 = read_map(fd, map_info);
	return (flag1);
}

int	read_map(int fd, t_map_info *map_info)
{
	char		*line;
	t_word_arr	words[MAP_MAXROWS + 1];
	size_t		idx;

	line = get_next_line(fd);
	if (line == NULL)
		return (FAIL);
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
	map_info->map = malloc(sizeof(t_vec3 *) * map_info->row);
	if (map_info->map == NULL)
		return (FAIL);
	return (check_map(map_info, words));
}

int	check_map(t_map_info *map_info, t_word_arr *words)
{
	size_t	idx;
	size_t	jdx;

	jdx = 0;
	while (words[0][jdx] != NULL)
		++jdx;
	idx = 0;
	map_info->col = jdx;
	while (idx < map_info->row && jdx == map_info->col)
	{
		map_info->map[idx] = malloc(sizeof(t_vec3) * map_info->col);
		jdx = 0;
		while (words[idx][jdx] != NULL && jdx < map_info->col)
		{
			map_info->map[idx][jdx] = ft_atoi(words[idx][jdx]);
			++jdx;
		}
		++idx;
	}
	map_info->row = idx;
	dealloc_words(words);
	return (!(jdx == map_info->col));
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
