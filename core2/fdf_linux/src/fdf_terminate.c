/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_terminate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:22:24 by hseong            #+#    #+#             */
/*   Updated: 2022/04/02 19:29:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

static void	dealloc_map(t_map_info *map_info, t_vertex **map);

void	terminate_fdf(t_mlx_info *mlx_info)
{
	ft_putstr_fd("terminating fdf\n", 2);
	dealloc_map(mlx_info->map_info, mlx_info->map_info->map_origin);
	dealloc_map(mlx_info->map_info, mlx_info->map_info->map_proj);
	mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->img_ptr);
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
}

void	dealloc_map(t_map_info *map_info, t_vertex **map)
{
	int		idx;

	idx = 0;
	while (idx < map_info->row)
	{
		free(map[idx]);
		++idx;
	}
	free(map);
}
