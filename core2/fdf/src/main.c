/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 12:41:34 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	fdf_loop(t_mlx_info *mlx_info);
static void	fdf_init(int argc, char **argv, t_mlx_info *mlx_info);

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_img_elem	img_elem;
	t_map_info	map_info;

	mlx_info.img_elem = &img_elem;
	mlx_info.map_info = &map_info;
	fdf_init(argc, argv, &mlx_info);
	mlx_key_hook(mlx_info.win_ptr, key_hook, &mlx_info);
	mlx_loop_hook(mlx_info.mlx_ptr, fdf_loop, &mlx_info);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}

void	fdf_init(int argc, char **argv, t_mlx_info *mlx_info)
{
	if (fdf_load_map(argc, argv, mlx_info->map_info) == FALSE)
	{
		ft_putstr_fd("invalid map format\n", 2);
		exit(64);
	}
	if (init_win(mlx_info) != 0 || init_img(mlx_info, mlx_info->img_elem) != 0)
	{
		perror("initialization failed");
		exit(128);
	}
	fdf_align_map(mlx_info->map_info);
	fdf_alloc_map(mlx_info->map_info);
	mlx_do_key_autorepeaton(mlx_info->mlx_ptr);
	ft_putstr_fd("rendering...\n", 1);
}

int	fdf_loop(t_mlx_info *mlx_info)
{
	mlx_sync(3, mlx_info->win_ptr);
	ft_memset(mlx_info->img_elem->img_buf, 0, mlx_info->img_elem->arr_bytes);
	fdf_projection(mlx_info);
	fdf_wireframe(mlx_info->img_elem, mlx_info->map_info);
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->win_ptr, mlx_info->img_ptr, 0, 0);
	mlx_info->map_info->hor_angle += 0.04;
	mlx_info->map_info->ver_angle += 0.04;
	mlx_info->map_info->gamma += 0.04;
	get_frametime(mlx_info);
	return (0);
}
//	system("leaks fdf | grep malloced");
