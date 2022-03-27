/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 15:10:25 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	fdf_loop(t_mlx_info *mlx_info);

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_img_elem	img_elem;
	t_map		map;

	if (fdf_load_map(argc, argv, &map) == FALSE)
	{
		ft_putstr_fd("invalid map format\n", 2);
		return (64);
	}
	mlx_info.img_elem = &img_elem;
	mlx_info.map = &map;
	if (init_win(&mlx_info) != 0
		|| init_img(&mlx_info, &img_elem) != 0)
	{
		perror("initialization failed");
		return (128);
	}
	ft_putstr_fd("rendering...\n", 1);
	fdf_projection(&mlx_info);
	mlx_key_hook(mlx_info.win_ptr, key_hook, NULL);
	mlx_loop_hook(mlx_info.mlx_ptr, fdf_loop, &mlx_info);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}

int	fdf_loop(t_mlx_info *mlx_info)
{
	get_frametime();
	mlx_sync(3, mlx_info->win_ptr);
	ft_memset(mlx_info->img_elem->img_arr, 0, mlx_info->img_elem->arr_bytes);
	fdf_wireframe(mlx_info->img_elem, mlx_info->map);
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->win_ptr, mlx_info->img_ptr, 0, 0);
	return (0);
}
