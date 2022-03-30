/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_interface.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:13:45 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 22:24:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_transform.h"

#define VEC_CENTER (50.0)
#define VEC_SIZE (40.0)

static void	draw_unitvector(t_map_info *map_info, t_img_elem *img_elem);

void	fdf_interface(t_mlx_info *mlx_info)
{
	draw_unitvector(mlx_info->map_info, mlx_info->img_elem);
}

void	draw_unitvector(t_map_info *map_info, t_img_elem *img_elem)
{
	static t_map_info	submap_info;
	static t_vertex		vec[6];

	vec[0] = (t_vertex){1.0, 0.0, 0.0, 0xFF1111};
	vec[1] = (t_vertex){0.0, 0.0, 0.0, 0xFF8888};
	vec[2] = (t_vertex){0.0, 1.0, 0.0, 0x11FF11};
	vec[3] = (t_vertex){0.0, 0.0, 0.0, 0x88FF88};
	vec[4] = (t_vertex){0.0, 0.0, 1.0, 0x4444FF};
	vec[5] = (t_vertex){0.0, 0.0, 0.0, 0x8888FF};

	submap_info = (t_map_info){
		.hor_scale = VEC_SIZE,
		.ver_scale = VEC_SIZE,
		.hor_angle = map_info->hor_angle,
		.ver_angle = map_info->ver_angle,
		.gamma = map_info->gamma,
		.x0 = VEC_CENTER,
		.y0 = VEC_CENTER + 20.0
	};
	isometric_proj(&submap_info, vec, vec);
	isometric_proj(&submap_info, vec + 1, vec + 1);
	isometric_proj(&submap_info, vec + 2, vec + 2);
	isometric_proj(&submap_info, vec + 3, vec + 3);
	isometric_proj(&submap_info, vec + 4, vec + 4);
	isometric_proj(&submap_info, vec + 5, vec + 5);
	fdf_drawline(img_elem, vec + 0, vec + 1);
	fdf_drawline(img_elem, vec + 0, vec + 2);
	fdf_drawline(img_elem, vec + 2, vec + 3);
	fdf_drawline(img_elem, vec + 2, vec + 4);
	fdf_drawline(img_elem, vec + 4, vec + 5);
	fdf_drawline(img_elem, vec + 4, vec + 0);
}
