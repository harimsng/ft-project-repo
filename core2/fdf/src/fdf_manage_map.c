/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_manage_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:31:12 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 19:36:40 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static t_bool	dealloc(t_vertex **arr, int len);

// align map to the center of the display.
// y coordinate is higher(lower in the display) than mid-value.
void	fdf_setup_map(t_mlx_info *mlx_info)
{
	t_map_info	*map_info;
	t_mlx_flag	*mlx_flag;

	mlx_flag = mlx_info->mlx_flag;
	map_info = mlx_info->map_info;
	map_info->x0 = SCREEN_WIDTH / 2;
	map_info->y0 = SCREEN_HEIGHT / 2;
	map_info->hor_angle = HOR_ANGLE;
	map_info->ver_angle = VER_ANGLE;
	if (map_info->arg_flag == FALSE)
	{
		map_info->hor_scale = (double)SCREEN_WIDTH
			/ (map_info->col + map_info->row);
		map_info->ver_scale = (double)SCREEN_HEIGHT
			/ (map_info->col + map_info->row + map_info->max_height / 2.0);
	}
	map_info->gamma = GAMMA;
	map_info->projection = 0;
	map_info->var_x = 0;
	map_info->var_y = 0;
	map_info->var_height = 0;
	mlx_flag->automove_flag = FALSE;
	mlx_flag->interface_flag = FALSE;
	mlx_flag->wireframe_flag = TRUE;
	mlx_flag->background_flag = FALSE;
}

t_bool	fdf_alloc_map(t_map_info *map_info)
{
	t_vertex	**projected;
	int			idx;

	projected = malloc(sizeof(t_vertex *) * map_info->row);
	if (projected == NULL)
		return (FALSE);
	idx = 0;
	while (idx < map_info->row)
	{
		projected[idx] = malloc(sizeof(t_vertex) * map_info->col);
		if (projected[idx] == NULL)
			return (dealloc(projected, idx));
		++idx;
	}
	map_info->map_proj = projected;
	return (TRUE);
}

static t_bool	dealloc(t_vertex **arr, int len)
{
	int		idx;

	idx = 0;
	while (idx < len)
	{
		free(arr[idx]);
		++idx;
	}
	free(arr);
	return (FALSE);
}
