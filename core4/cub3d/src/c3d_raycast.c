/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:59:26 by hseong            #+#    #+#             */
/*   Updated: 2022/05/24 03:17:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_const.h"
#include <stdio.h>
#include <math.h>

static const double g_fov = FOV * M_PI / 180;
static const double	g_half_fov = FOV * M_PI / 360;
static const double	g_angle_step = FOV * M_PI / SCREEN_WIDTH / 180.0;

void	c3d_raycast(t_mlx_info *mlx_info, t_camera *camera)
{
	double		angle;
	t_vec2		point;
	t_vec2		camera_vec2;
	t_camera	temp;
	int			count;

	if (camera->angle < 0)
		camera->angle += 2.0 * M_PI;
	else if (camera->angle >= 2.0 * M_PI)
		camera->angle -= 2.0 * M_PI;
	angle = 0.0;
	count = 0;
	camera_vec2 = (t_vec2){camera->x, camera->y};
	while (count < SCREEN_WIDTH)
	{
		temp = (t_camera){camera->angle - g_half_fov + angle,
			camera->x, camera->y};
		c3d_draw_vline(c3d_detect_wall(mlx_info->map_info, &temp, &point),
			mlx_info, count,
			cos(angle - g_half_fov) * vec2_dist(&camera_vec2, &point));
		angle += g_angle_step;
		++count;
	}
}

void	c3d_raycast_overview(t_mlx_info *mlx_info, t_camera *camera)
{
	int			count;
	double		angle;
	t_vec2		point;
	t_camera	temp_camera;
	t_vec4		draw_points[2];

	c3d_background(mlx_info);
	if (camera->angle < 0)
		camera->angle += 2.0 * M_PI;
	else if (camera->angle >= 2.0 * M_PI)
		camera->angle -= 2.0 * M_PI;
	angle = 0.0;
	draw_points[0] = (t_vec4){camera->x, camera->y, 0, 0xFF2F2F};
	count = 0;
	while (angle < g_fov)
	{
		temp_camera = (t_camera){camera->angle - g_half_fov + angle,
			camera->x, camera->y};
		c3d_detect_wall(mlx_info->map_info, &temp_camera, &point);
		draw_points[1] = (t_vec4){point.x, point.y, 0, 0xFF2F2F};
		if (count % 5 == 0)
			c3d_drawline(mlx_info->img_elem, draw_points, draw_points + 1);
		angle += g_angle_step;
		++count;
	}
}
