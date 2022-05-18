/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_detect_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:48:13 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 20:10:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "c3d_const.h"

// 0b1000 down 		0b0100 top
// 0b0010 right		0b0001 left
int	c3d_detect_collision(t_camera *camera, t_mlx_info *mlx_info)
{
	int		**map;
	size_t	jdx;
	size_t	idx;

	map = mlx_info->map_info->map;
	jdx = ((int)camera->y >> LOG_GRID_WIDTH);
	idx = ((int)camera->x >> LOG_GRID_WIDTH);
	if (idx >= mlx_info->map_info->col || jdx >= mlx_info->map_info->row)
		return (0);
	if (map[jdx][idx] == 1)
		return (0);
	return (1);
}
