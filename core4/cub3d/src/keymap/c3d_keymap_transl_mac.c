/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keymap_transl_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:23 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 21:39:42 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_const.h"
#include "c3d_keymap.h"
#include <math.h>

// require MacOS Keycode
void	move_obj_left(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	double		dx;
	double		dy;

	camera = mlx_info->camera;
	dx = X_STEP * cos(camera->angle);
	dy = X_STEP * sin(camera->angle);
	camera->x -= dx;
	camera->y -= dy;
	if (c3d_detect_collision(camera, mlx_info) == 0)
	{
		camera->x += dx;
		camera->y += dy;
	}
}

void	move_obj_right(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	double		dx;
	double		dy;

	camera = mlx_info->camera;
	dx = X_STEP * cos(camera->angle);
	dy = X_STEP * sin(camera->angle);
	camera->x += dx;
	camera->y += dy;
	if (c3d_detect_collision(mlx_info->camera, mlx_info) == 0)
	{
		camera->x -= dx;
		camera->y -= dy;
	}
}

void	move_obj_forward(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	double		dx;
	double		dy;

	camera = mlx_info->camera;
	dx = Y_STEP * sin(camera->angle);
	dy = Y_STEP * cos(camera->angle);
	camera->x += dx;
	camera->y -= dy;
	if (c3d_detect_collision(mlx_info->camera, mlx_info) == 0)
	{
		camera->x -= dx;
		camera->y += dy;
	}
}

void	move_obj_back(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	double		dx;
	double		dy;

	camera = mlx_info->camera;
	dx = Y_STEP * sin(camera->angle);
	dy = Y_STEP * cos(camera->angle);
	camera->x -= dx;
	camera->y += dy;
	if (c3d_detect_collision(mlx_info->camera, mlx_info) == 0)
	{
		camera->x += dx;
		camera->y -= dy;
	}
}
