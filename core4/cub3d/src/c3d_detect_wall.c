/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_detect_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:39:28 by hseong            #+#    #+#             */
/*   Updated: 2022/06/06 05:58:46 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "c3d.h"
#include "c3d_type.h"

#define SAFE_ANGLE (0.005)

typedef double	(*t_ftoi)(double);

static int
north_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point);
static int
east_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point);
static int
south_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point);
static int
west_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point);

int
c3d_detect_wall(t_map_info *map_info, t_camera *camera, t_vec2 *point)
{
	int		contact;
	double	angle;
	t_vec2	ver_point;
	t_vec2	hor_point;

	ver_point = (t_vec2){camera->x, camera->y};
	hor_point = (t_vec2){camera->x, camera->y};
	contact = 0;
	angle = camera->angle;
	while (angle < 0.0)
		angle += 2.0 * M_PI;
	while (angle >= 2.0 * M_PI)
		angle -= 2.0 * M_PI;
	if (angle > M_PI_2 + SAFE_ANGLE && angle < M_PI + M_PI_2 - SAFE_ANGLE)
		contact |= south_ray(map_info, camera, &hor_point);
	else if (angle < M_PI_2 - SAFE_ANGLE || angle > M_PI_2 + M_PI + SAFE_ANGLE)
		contact |= 2 * north_ray(map_info, camera, &hor_point);
	if (angle < M_PI - SAFE_ANGLE && angle > SAFE_ANGLE)
		contact |= 4 * east_ray(map_info, camera, &ver_point);
	else if (angle > M_PI + SAFE_ANGLE && angle < 2 * M_PI - SAFE_ANGLE)
		contact |= 8 * west_ray(map_info, camera, &ver_point);
	if ((contact & 3) == 0
		|| (((contact & 12) != 0) && vec2_dist(&(t_vec2){camera->x, camera->y}, &hor_point)
		> vec2_dist(&(t_vec2){camera->x, camera->y}, &ver_point)))
	{
		*point = ver_point;
		contact = lround(point->y);
	}
	else
	{
		*point = hor_point;
		contact = lround(point->x);
	}
	return (contact);
}

int
north_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point)
{
	size_t	map_x;
	size_t	map_y;
	double	ratio;
	t_ftoi	ftoi;

	ftoi = floor;
	ratio = tan(camera->angle);
	if (ratio < 0)
		ftoi = ceil;
	map_x = (int)camera->x / GRID_WIDTH;
	map_y = (int)camera->y / GRID_WIDTH;
	point->y = map_y * GRID_WIDTH - 1;
	point->x += (camera->y - point->y) * ratio;
	map_x = ftoi(point->x) / GRID_WIDTH;
	map_y = (int)(point->y) / GRID_WIDTH;
	while (map_x < map_info->col && map_y < map_info->row
		&& map_info->map[map_y][map_x] != 1)
	{
		point->y -= GRID_WIDTH;
		point->x += GRID_WIDTH * ratio;
		map_x = ftoi(point->x) / GRID_WIDTH;
		map_y = (int)(point->y) / GRID_WIDTH;
	}
	return (1);
}

int
south_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point)
{
	size_t	map_x;
	size_t	map_y;
	double	ratio;
	t_ftoi	ftoi;

	ftoi = floor;
	ratio = tan(M_PI - camera->angle);
	if (ratio < 0)
		ftoi = ceil;
	map_x = (int)camera->x / GRID_WIDTH;
	map_y = (int)camera->y / GRID_WIDTH;
	point->y = (map_y + 1) * GRID_WIDTH;
	point->x += (point->y - camera->y) * ratio;
	map_x = ftoi(point->x) / GRID_WIDTH;
	map_y = (int)point->y / GRID_WIDTH;
	while (map_x < map_info->col && map_y < map_info->row
		&& map_info->map[map_y][map_x] != 1)
	{
		point->y += GRID_WIDTH;
		point->x += GRID_WIDTH * ratio;
		map_x = ftoi(point->x) / GRID_WIDTH;
		map_y = (int)(point->y) / GRID_WIDTH;
	}
	return (1);
}

int
east_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point)
{
	size_t	map_x;
	size_t	map_y;
	double	ratio;
	t_ftoi	ftoi;

	ftoi = floor;
	ratio = tan(camera->angle - M_PI_2);
	if (ratio < 0)
		ftoi = ceil;
	map_x = (int)camera->x / GRID_WIDTH;
	map_y = (int)camera->y / GRID_WIDTH;
	point->x = (map_x + 1) * GRID_WIDTH;
	point->y += (point->x - camera->x) * ratio;
	map_x = (int)(point->x) / GRID_WIDTH;
	map_y = ftoi(point->y) / GRID_WIDTH;
	while (map_x < map_info->col && map_y < map_info->row
		&& map_info->map[map_y][map_x] != 1)
	{
		point->x += GRID_WIDTH;
		point->y += GRID_WIDTH * ratio;
		map_x = (int)(point->x) / GRID_WIDTH;
		map_y = ftoi(point->y) / GRID_WIDTH;
	}
	return (1);
}

int
west_ray(t_map_info *map_info, const t_camera *camera, t_vec2 *point)
{
	size_t	map_x;
	size_t	map_y;
	double	ratio;
	t_ftoi	ftoi;

	ftoi = floor;
	ratio = tan(M_PI + M_PI_2 - camera->angle);
	if (ratio < 0)
		ftoi = ceil;
	map_x = (int)camera->x / GRID_WIDTH;
	map_y = (int)camera->y / GRID_WIDTH;
	point->x = map_x * GRID_WIDTH - 1;
	point->y += (camera->x - point->x) * ratio;
	map_x = (int)(point->x) / GRID_WIDTH;
	map_y = ftoi(point->y) / GRID_WIDTH;
	while (map_x < map_info->col && map_y < map_info->row 
		&& map_info->map[map_y][map_x] != 1)
	{
		point->x -= GRID_WIDTH;
		point->y += GRID_WIDTH * ratio;
		map_x = (int)(point->x) / GRID_WIDTH;
		map_y = ftoi(point->y) / GRID_WIDTH;
	}
	return (1);
}
