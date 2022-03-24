/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:31:05 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 18:01:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_update(t_img_elem *img_elem);

int	fdf_loop(t_mlx_info *mlx_info)
{
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->win_ptr, mlx_info->img_ptr, 0, 0);
	ft_memset(mlx_info->img_elem->img_arr, 0, mlx_info->img_elem->arr_bytes);
	fdf_plot(0, 0);
	fdf_plot(1, 1);
	fdf_plot(0, 1);
	fdf_plot(1, 0);
	fdf_wireframe(mlx_info->img_elem, mlx_info->map);
	get_frametime();
	if (0)
		fdf_update(mlx_info->img_elem);
	return (0);
}

void	fdf_update(t_img_elem *img_elem)
{
	static int	frame;
	t_pixel		*img_arr;
	int			idx;
	int			x;
	int			y;

	get_frametime();
	img_arr = img_elem->img_arr;
	idx = 0;
	y = 0;
	write(2, ".", 1);
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			img_arr[idx] = fdf_plot(x + frame, y);
			++x;
			++idx;
		}
		++y;
		idx = y * img_elem->hor_size;
	}
	++frame;
}

// frame overflow
int		fdf_plot(int x, int y)
{
	double	val;
	double	val2;
	int		color;

	color = 0;
	val = (double)screen_hhalf * sin(M_PI * x / 180.0);
	val2 = (double)screen_hhalf * cos(M_PI * x / 180.0);
	if (y - screen_hhalf < val + 1 && y - screen_hhalf > val - 1)
		color |= 0x00FF0000;
	if (y - screen_hhalf < val2 + 1 && y - screen_hhalf > val2 - 1)
		color |= 0x0000FF00;
	if (y - screen_hhalf > -val - 1 && y - screen_hhalf < -val + 1)
		color |= 0x000000FF;
	if (y - screen_hhalf < 0.5 && y - screen_hhalf > -0.5)
		color |= 0x00FFFFFF;
//	color |= 0x100 * x / SCREEN_WIDTH * 0x10000;
	color |= 0x100 * y / SCREEN_HEIGHT;
	return (color);
}
