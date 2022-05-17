/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:22:24 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 07:58:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "c3d.h"
#include "libft.h"
#include <stdlib.h>

static void	terminate_c3d(t_mlx_info *mlx_info);
static void	dealloc_map(t_map_info *map_info, int **map);

void	c3d_exit(int status, t_mlx_info *mlx_info)
{
	ft_putstr_fd("terminating c3d\n", 2);
	terminate_c3d(mlx_info);
	exit(status);
}
//	system("leaks cub3d");
//	while (1)
//		continue ;

void	terminate_c3d(t_mlx_info *mlx_info)
{
	if (mlx_info->sub_ptr != NULL)
		mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->sub_ptr);
	if (mlx_info->img_ptr != NULL)
		mlx_destroy_image(mlx_info->mlx_ptr, mlx_info->img_ptr);
	if (mlx_info->win_ptr != NULL)
		mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	dealloc_map(mlx_info->map_info, mlx_info->map_info->map);
}

void	dealloc_map(t_map_info *map_info, int **map)
{
	size_t	idx;

	idx = 0;
	while (idx < map_info->row)
	{
		free(map[idx]);
		++idx;
	}
	free(map);
}
