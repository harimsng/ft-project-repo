/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 19:23:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_map *map);

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_img_elem	img_elem;
	t_map		map;

	if (fdf_parse_map(argc, argv, &map) == FALSE)
	{
		ft_putstr_fd("invalid map format\n", 2);
		return (64);
	}
		print_map(&map);
	mlx_info.map = &map;
	if (init_win(&mlx_info) != 0
		|| init_img(&mlx_info, &img_elem) != 0)
	{
		perror("initialization failed");
		return (128);
	}
	mlx_key_hook(mlx_info.win_ptr, key_hook, NULL);
	mlx_loop_hook(mlx_info.mlx_ptr, fdf_loop, &mlx_info);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}

void	print_map(t_map *map)
{
	for (int i = 0; i < map->row; ++i)
	{
		printf("_ ");
		for (int j = 0; j < map->col; ++j)
			printf("%d  ", map->map[i][j].z);
		printf("\n");
	}
}
