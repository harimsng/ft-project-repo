/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_terminate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:22:24 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 15:11:39 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

static void	terminate_fdf(t_mlx_info *mlx_info);
static void	dealloc_map(t_map_info *map_info, t_vertex **map);

void	fdf_exit(int status, t_mlx_info *mlx_info)
{
	ft_putstr_fd("terminating fdf\n", 2);
	terminate_fdf(mlx_info);
	exit(status);
}
//	system("leaks fdf");
//	while (1)
//		continue ;

void	terminate_fdf(t_mlx_info *mlx_info)
{
	if (mlx_info->sub_ptr != NULL)
		mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->sub_ptr);
	if (mlx_info->img_ptr != NULL)
		mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->img_ptr);
	if (mlx_info->win_ptr != NULL)
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	dealloc_map(mlx_info->map_info, mlx_info->map_info->map_origin);
	if (mlx_info->map_info->map_proj != NULL)
		dealloc_map(mlx_info->map_info, mlx_info->map_info->map_proj);
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
