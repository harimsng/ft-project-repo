/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_fill_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:53:31 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 22:25:41 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_fill_floor(t_mlx_info *mlx_info, t_pixel *img_buf)
{
	int		color;
	size_t	horizontal_pixel;
	size_t	idx;
	size_t	jdx;
	double	color_ratio;

	img_buf = mlx_info->img_elem->img_buf;
	horizontal_pixel = mlx_info->img_elem->hor_px;
	jdx = 0;
	while (jdx < SCREEN_HEIGHT)
	{
		if (jdx < SCREEN_HEIGHT >> 1)
			color_ratio
				= (double)((SCREEN_HEIGHT >> 1) - jdx) / (SCREEN_HEIGHT >> 1);
		else
			color_ratio
				= (double)(jdx - (SCREEN_HEIGHT >> 1)) / (SCREEN_HEIGHT >> 1);
		idx = 0;
		color = (int)(0x66 * color_ratio);
		color = (color << 16) + (color << 8) + color;
		while (idx < SCREEN_WIDTH)
		{
			img_buf[jdx * horizontal_pixel + idx] = color;
			++idx;
		}
		++jdx;
	}
}
