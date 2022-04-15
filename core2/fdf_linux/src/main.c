/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/04/15 15:56:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

static int	fdf_loop(t_mlx_info *mlx_info);
static void	fdf_init(int argc, char **argv, t_mlx_info *mlx_info);
static void	fdf_task(t_mlx_info *mlx_info);
static void	fdf_thread_join(t_mlx_info *mlx_info);

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_img_elem	img_elem;
	t_map_info	map_info;
	t_img_elem	sub_elem;
	t_mlx_flag	mlx_flag;

	ft_memset(&mlx_info, 0, sizeof(t_mlx_info));
	mlx_info.img_elem = &img_elem;
	mlx_info.map_info = &map_info;
	mlx_info.sub_elem = &sub_elem;
	mlx_info.mlx_flag = &mlx_flag;
	fdf_init(argc, argv, &mlx_info);
	mlx_key_hook(mlx_info.win_ptr, key_hook, &mlx_info);
	mlx_loop_hook(mlx_info.mlx_ptr, fdf_loop, &mlx_info);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}

void	fdf_init(int argc, char **argv, t_mlx_info *mlx_info)
{
	ft_memset(mlx_info->map_info, 0, sizeof(t_map_info));
	if (fdf_load_map(argc, argv, mlx_info->map_info) == FALSE)
	{
		ft_putstr_fd("invalid map format\n", 2);
		fdf_exit(0x1, mlx_info);
	}
	if (init_win(mlx_info) != 0 || init_img(mlx_info, mlx_info->img_elem) != 0)
	{
		perror("initialization failed");
		fdf_exit(0x2, mlx_info);
	}
	if (init_sub(mlx_info) != 0)
		perror("sub-image initialization failed");
	fdf_setup_map(mlx_info);
	if (fdf_alloc_map(mlx_info->map_info) == FALSE)
	{
		ft_putstr_fd("memory allocation failed\n", 2);
		fdf_exit(0x2, mlx_info);
	}
	mlx_do_key_autorepeaton(mlx_info->mlx_ptr);
	ft_putstr_fd("rendering scene\n", 1);
}

int	fdf_loop(t_mlx_info *mlx_info)
{
//	if (mlx_info->mlx_flag->wireframe_flag == TRUE)
	fdf_projection(mlx_info->map_info, mlx_info->thread);
	fdf_thread_join(mlx_info);
	fdf_task(mlx_info);
//	if (mlx_info->mlx_flag->wireframe_flag == TRUE)
	fdf_wireframe(mlx_info->img_elem, mlx_info->map_info);
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->win_ptr, mlx_info->img_ptr, 0, SUBIMG_HEIGHT);
	return (0);
}

void	fdf_task(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;
	int			x;
	int			y;

	map_info = mlx_info->map_info;
	fdf_mouse_get_pos(mlx_info, &x, &y);
	map_info->var_y += y * cos(map_info->hor_angle) + x * sin(map_info->hor_angle);
	map_info->var_x += -y * sin(map_info->hor_angle) + x * cos(map_info->hor_angle);
//	map_info->var_x = (x - g_screen_hwidth) * cos(map_info->hor_angle)
//	map_info->var_y = (y - g_screen_hheight) * sin(map_info->hor_angle)
	mlx_do_sync(mlx_info->mlx_ptr);
	ft_memset(mlx_info->img_elem->img_buf, 0, mlx_info->img_elem->arr_bytes);
	ft_memset(mlx_info->sub_elem->img_buf, 0, mlx_info->sub_elem->arr_bytes);
	//if (mlx_info->mlx_flag->background_flag)
	//	fdf_plot_loop(mlx_info);
	if (mlx_info->mlx_flag->automove_flag == TRUE)
	{
		map_info->var_x *= 1.04;
		map_info->var_y *= 1.04;
		mlx_info->map_info->fract_scale *= 1.04;
		mlx_info->map_info->hor_angle += 0.01;
//		map_info->ver_angle += 0.03;
	}
	fdf_interface(mlx_info);
}

void	fdf_thread_join(t_mlx_info *mlx_info)
{
	size_t		idx;
	pthread_t	*thread;

	thread = mlx_info->thread;
	idx = 0;
	while (idx < SCREEN_HEIGHT)
		pthread_join(thread[idx++], NULL);
}
