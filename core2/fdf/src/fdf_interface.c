/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:13:45 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 21:59:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_transform.h"

#define VEC_SIZE (40.0)
#define VEC_X (SCREEN_WIDTH / 2)
#define VEC_Y (SUBIMG_HEIGHT / 2)

static void	draw_unitvector(t_map_info *map_info, t_img_elem *img_elem);

void	fdf_interface(t_mlx_info *mlx_info)
{
	draw_unitvector(mlx_info->map_info, mlx_info->sub_elem);
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
		.gamma = map_info->gamma, .x0 = VEC_X, .y0 = VEC_Y
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
