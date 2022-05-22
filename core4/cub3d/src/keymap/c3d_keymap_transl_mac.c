/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keymap_transl_mac.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:22:23 by hseong            #+#    #+#             */
/*   Updated: 2022/05/22 21:57:36 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_const.h"
#include "c3d_keymap.h"
#include <math.h>

#define LOG LOG_GRID_WIDTH

// require MacOS Keycode
void	move_obj_left(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	int			**map;
	double		dx;
	double		dy;

	map = mlx_info->map_info->map;
	camera = mlx_info->camera;
	dx = X_STEP * cos(camera->angle);
	dy = X_STEP * sin(camera->angle);
	if (map[(int)camera->y >> LOG][(int)(camera->x - dx) >> LOG] == 0)
		camera->x -= dx;
	if (map[(int)(camera->y - dy) >> LOG][(int)camera->x >> LOG] == 0)
		camera->y -= dy;
}

void	move_obj_right(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	int			**map;
	double		dx;
	double		dy;

	map = mlx_info->map_info->map;
	camera = mlx_info->camera;
	dx = X_STEP * cos(camera->angle);
	dy = X_STEP * sin(camera->angle);
	if (map[(int)camera->y >> LOG][(int)(camera->x + dx) >> LOG] == 0)
		camera->x += dx;
	if (map[(int)(camera->y + dy) >> LOG][(int)camera->x >> LOG] == 0)
		camera->y += dy;
}

void	move_obj_forward(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	int			**map;
	double		dx;
	double		dy;

	map = mlx_info->map_info->map;
	camera = mlx_info->camera;
	dx = Y_STEP * sin(camera->angle);
	dy = Y_STEP * cos(camera->angle);
	if (map[(int)camera->y >> LOG][(int)(camera->x + dx) >> LOG] == 0)
		camera->x += dx;
	if (map[(int)(camera->y - dy) >> LOG][(int)camera->x >> LOG] == 0)
		camera->y -= dy;
}

void	move_obj_back(t_mlx_info *mlx_info)
{
	t_camera	*camera;
	int			**map;
	double		dx;
	double		dy;

	map = mlx_info->map_info->map;
	camera = mlx_info->camera;
	dx = Y_STEP * sin(camera->angle);
	dy = Y_STEP * cos(camera->angle);
	if (map[(int)camera->y >> LOG][(int)(camera->x - dx) >> LOG] == 0)
		camera->x -= dx;
	if (map[(int)(camera->y + dy) >> LOG][(int)camera->x >> LOG] == 0)
		camera->y += dy;
}
