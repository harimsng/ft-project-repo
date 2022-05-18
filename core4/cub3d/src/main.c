/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 22:14:23 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include "libft.h"
#include <stdio.h>
#include <math.h>

#define TEXTURE_DIR ("../resource")

static int	c3d_loop(t_mlx_info *mlx_info);
static void	c3d_init(int argc, char **argv, t_mlx_info *mlx_info);
static void	c3d_task(t_mlx_info *mlx_info);
//static void	c3d_thread_join(t_mlx_info *mlx_info);

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_img_elem	img_elem;
	t_map_info	map_info;
	t_resource	resource;
	t_camera	camera;

	ft_memset(&mlx_info, 0, sizeof(t_mlx_info));
	mlx_info.img_elem = &img_elem;
	mlx_info.map_info = &map_info;
	mlx_info.resource = &resource;
	mlx_info.camera = &camera;
	c3d_init(argc, argv, &mlx_info);
	mlx_key_hook(mlx_info.win_ptr, key_hook, &mlx_info);
	mlx_loop_hook(mlx_info.mlx_ptr, c3d_loop, &mlx_info);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}

void	c3d_init(int argc, char **argv, t_mlx_info *mlx_info)
{
	ft_memset(mlx_info->map_info, 0, sizeof(t_map_info));
	if (c3d_load_map(argc, argv, mlx_info->map_info) == FALSE)
	{
		ft_putstr_fd("invalid map format\n", 2);
		c3d_exit(0x1, mlx_info);
	}
//	if (c3d_load_texture(TEXTURE_DIR, mlx_info) == FALSE)
//	{
//		ft_putstr_fd("unable to get texture data\n", 2);
//		c3d_exit(0x1, mlx_info);
//	}
	if (init_win(mlx_info) != 0 || init_img(mlx_info, mlx_info->img_elem) != 0)
	{
		perror("initialization failed");
		c3d_exit(0x2, mlx_info);
	}
	/*
	if (init_sub(mlx_info) != 0)
		perror("sub-image initialization failed");
	*/
	mlx_do_key_autorepeaton(mlx_info->mlx_ptr);
	ft_putstr_fd("rendering scene\n", 1);
	*mlx_info->camera = (t_camera){0, 250, 250};
}

int	c3d_loop(t_mlx_info *mlx_info)
{
//	c3d_thread_join(mlx_info);
	c3d_task(mlx_info);
	c3d_fill_floor(mlx_info, mlx_info->img_elem->img_buf);
	c3d_raycast(mlx_info, mlx_info->camera);
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->win_ptr, mlx_info->img_ptr, 0, SUBIMG_HEIGHT);
	return (0);
}

void	c3d_task(t_mlx_info *mlx_info)
{
	int		x;
	int		y;

	c3d_mouse_get_pos(mlx_info, &x, &y);
	mlx_info->camera->angle += x * MOUSE_SENSITIVITY;
	mlx_do_sync(mlx_info->mlx_ptr);
	ft_memset(mlx_info->img_elem->img_buf, 0, mlx_info->img_elem->arr_bytes);
//	ft_memset(mlx_info->sub_elem->img_buf, 0, mlx_info->sub_elem->arr_bytes);
}

/*
void	c3d_thread_join(t_mlx_info *mlx_info)
{
	size_t		idx;
	pthread_t	*thread;

	thread = mlx_info->thread;
	idx = 0;
	while (idx < SCREEN_HEIGHT)
		pthread_join(thread[idx++], NULL);
}
*/
