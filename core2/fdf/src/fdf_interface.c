/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:13:45 by hseong            #+#    #+#             */
/*   Updated: 2022/04/02 21:01:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_transform.h"
#include "mlx.h"
#include <time.h>
#include <stdio.h>

#define VEC_SIZE (40.0)
#define VEC_X (SCREEN_WIDTH)
#define VEC_Y (SUBIMG_HEIGHT)

static void	draw_unitvector(t_map_info *map_info, t_img_elem *img_elem);

void	fdf_interface(t_mlx_info *mlx_info)
{
	draw_unitvector(mlx_info->map_info, mlx_info->sub_elem);
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->win_ptr, mlx_info->sub_ptr, 0, 0);
	draw_unitvector(mlx_info->map_info, mlx_info->sub_elem);
	fdf_debug(mlx_info);
	get_frametime(mlx_info, mlx_info->map_info);
}

void	draw_unitvector(t_map_info *map_info, t_img_elem *sub_elem)
{
	static t_map_info	submap_info;
	static t_vertex		vec[6];
	int					idx;

	vec[0] = (t_vertex){1.0, 0.0, 0.0, 0xFF1111};
	vec[1] = (t_vertex){0.0, 0.0, 0.0, 0xFF8888};
	vec[2] = (t_vertex){0.0, 1.0, 0.0, 0x11FF11};
	vec[3] = (t_vertex){0.0, 0.0, 0.0, 0x88FF88};
	vec[4] = (t_vertex){0.0, 0.0, 1.0, 0x4444FF};
	vec[5] = (t_vertex){0.0, 0.0, 0.0, 0x8888FF};
	submap_info = (t_map_info){
		.hor_scale = VEC_SIZE, .ver_scale = VEC_SIZE,
		.hor_angle = map_info->hor_angle, .ver_angle = map_info->ver_angle,
		.gamma = map_info->gamma, .x0 = VEC_X / 2, .y0 = VEC_Y / 2
	};
	idx = -1;
	while (++idx < 6)
		isometric_proj(&submap_info, vec + idx, vec + idx);
	idx = -1;
	while (++idx < 3)
	{
		fdf_drawline(sub_elem, vec + idx * 2, vec + (idx * 2 + 1) % 6);
		fdf_drawline(sub_elem, vec + idx * 2, vec + (idx * 2 + 2) % 6);
	}
}

void	get_frametime(t_mlx_info *mlx_info, t_map_info *map_info)
{
	static int		frame;
	static clock_t	past;
	static clock_t	now;
	float			frametime;
	char			buf[100];

	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	past = now;
	snprintf(buf, 100, "fps = %6.2f  frametime = %6.4f \
alpha = %6.2fdeg beta = %6.2lfdeg gamma = %6.2lfdeg",
		1 / frametime, frametime,
		fmod(map_info->hor_angle * 180.0 / M_PI, 360.0),
		fmod(map_info->ver_angle * 180.0 / M_PI, 360.0),
		fmod(map_info->gamma * 180.0 / M_PI, 360.0));
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr,
		0, TEXT_HEIGHT, 0xFFFFFF, buf);
	++frame;
}

void	fdf_debug(t_mlx_info *mlx_info)
{
	char		buf[100];
	t_map_info	*map_info;

	map_info = mlx_info->map_info;
	snprintf(buf, 100,
		"x = %5d y = %5d dx = %4.2lf dy = %4.2lf",
		map_info->x0 - g_screen_hwidth,
		map_info->y0 - g_screen_hheight,
		map_info->hor_scale, map_info->ver_scale);
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr,
		0, 2 * TEXT_HEIGHT + 4, 0xFFFFFF, buf);
}
