/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_detect_hor_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:39:28 by hseong            #+#    #+#             */
/*   Updated: 2022/05/17 23:35:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include <math.h>

#define GRID_WIDTH (128)
#define MAP_WIDTH (8)
#define MAP_HEIGHT (8)

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;
typedef int		(*t_ray_table)(double, int, int, t_point *point);

static int	north_ray(double angle, int x, int y, t_point *point);
static int	east_ray(double angle, int x, int y, t_point *point);
static int	south_ray(double angle, int x, int y, t_point *point);
static int	west_ray(double angle, int x, int y, t_point *point);

static const t_ray_table	g_ray_table[4]
	= {
	north_ray,
	east_ray,
	south_ray,
	west_ray
};

int	c3d_detect_hor_wall(double angle, int x, int y, t_point *point)
{
	int		idx;

	if (angle < 0.)
		angle += 2 * M_PI;
	else if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	idx = (angle + M_PI_4) / M_PI_2;
	idx &= 0b11;
	return (g_ray_table[idx](angle, x, y, point));
}

int	north_ray(double angle, int x, int y, t_point *point)
{
	int		map_x;
	int		map_y;
	int		ver_x;
	int		ver_y;
	double	ratio;

	ratio = tan(angle);
	map_x = x % GRID_WIDTH;
	map_y = y % GRID_WIDTH;
	map_y *= GRID_WIDTH;
	map_y = y - map_y;
	map_x = map_y * ratio;
	ver_x = (map_x + 1) * GRID_WIDTH;
	point->x += map_x;
	point->y -= map_y;
	while (map_x >= 0 && map_y >= 0
			&& map_x < MAP_WIDTH
			&& map_y < MAP_HEIGHT
			&& g_grid[map_x + MAP_WIDTH * map_y] != 1)
	{
		point->y -= GRID_WIDTH;
		point->x += GRID_WIDTH * ratio;
		map_x = point->x % GRID_WIDTH;
		map_y = point->y % GRID_WIDTH;
	}
}

int	east_ray(double angle, int x, int y, t_point *point)
{
	int		map_x;
	int		map_y;
	double	ratio;

	ratio = tan(M_PI_2 - angle);
	map_x = x % GRID_WIDTH;
	map_y = y % GRID_WIDTH;
	map_x = (map_x + 1) * GRID_WIDTH - x;
	map_y = map_x * ratio;
	point->x += map_x;
	point->y += map_y;
	while (map_x >= 0 && map_y >= 0
			&& map_x < MAP_WIDTH
			&& map_y < MAP_HEIGHT
			&& g_grid[map_x + MAP_WIDTH * map_y] != 1)
	{
		point->x += GRID_WIDTH;
		point->y += GRID_WIDTH * ratio;
		map_x = point->x % GRID_WIDTH;
		map_y = point->y % GRID_WIDTH;
	}
}

int	south_ray(double angle, int x, int y, t_point *point)
{
	int		map_x;
	int		map_y;
	double	ratio;

	ratio = -tan(M_PI - angle);
	map_x = x % GRID_WIDTH;
	map_y = y % GRID_WIDTH;
	map_y *= GRID_WIDTH;
	map_y = (map_y + 1) * MAP_WIDTH - y;
	map_x = map_y * ratio;
	point->x += map_x;
	point->y += map_y;
	while (map_x >= 0 && map_y >= 0
			&& map_x < MAP_WIDTH
			&& map_y < MAP_HEIGHT
			&& g_grid[map_x + MAP_WIDTH * map_y] != 1)
	{
		point->y += GRID_WIDTH;
		point->x += GRID_WIDTH * ratio;
		map_x = point->x % GRID_WIDTH;
		map_y = point->y % GRID_WIDTH;
	}
}

int	west_ray(double angle, int x, int y, t_point *point)
{
	int		map_x;
	int		map_y;
	double	ratio;

	ratio = -tan(M_PI_2 + M_PI - angle);
	map_x = x % GRID_WIDTH;
	map_y = y % GRID_WIDTH;
	map_x = x - map_x;
	map_y = map_x * ratio;
	point->x += map_x;
	point->y += map_y;
	while (map_x >= 0 && map_y >= 0
			&& map_x < MAP_WIDTH
			&& map_y < MAP_HEIGHT
			&& g_grid[map_x + MAP_WIDTH * map_y] != 1)
	{
		point->x -= GRID_WIDTH;
		point->y += GRID_WIDTH * ratio;
		map_x = point->x % GRID_WIDTH;
		map_y = point->y % GRID_WIDTH;
	}
}
