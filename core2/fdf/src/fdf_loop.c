/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:31:05 by hseong            #+#    #+#             */
/*   Updated: 2022/03/22 16:09:43 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include "time.h"
# include <stdio.h>

static void	fdf_update(t_img_elem *img_elem);
static void	get_frametime(void);

int	fdf_loop(t_mlx_info *mlx_info)
{
	mlx_put_image_to_window(mlx_info->mlx_ptr,
		mlx_info->win_ptr, mlx_info->img_ptr, 0, 0);
	fdf_update(mlx_info->img_elem);
	return (0);
}

void	fdf_update(t_img_elem *img_elem)
{
	static int	frame = 0;
	t_pixel	*img_arr;
	int		idx;
	int		x;
	int		y;

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
	fdf_drawline(img_elem, 0, 0, 500, 250);
	fdf_drawline(img_elem, 10, 10, 500, 250);
	fdf_drawline(img_elem, 20, 20, 500, 250);
	fdf_drawline(img_elem, 30, 30, 500, 250);
	fdf_drawline(img_elem, 40, 40, 500, 250);
	fdf_drawline(img_elem, 50, 50, 500, 250);
	fdf_drawline(img_elem, 60, 60, 500, 250);
	fdf_drawline(img_elem, 70, 70, 500, 250);
	fdf_drawline(img_elem, 80, 80, 500, 250);
	fdf_drawline(img_elem, 90, 80, 500, 250);
	fdf_drawline(img_elem, 100, 80, 500, 250);
	fdf_drawline(img_elem, 200, 80, 500, 250);
	fdf_drawline(img_elem, 300, 80, 500, 250);
	fdf_drawline(img_elem, 400, 80, 500, 250);
	fdf_drawline(img_elem, 500, 80, 500, 250);
	fdf_drawline(img_elem, 600, 80, 500, 250);
	fdf_drawline(img_elem, 700, 80, 500, 250);
	fdf_drawline(img_elem, 800, 80, 500, 250);
	++frame;
}

// frame overflow
int		fdf_plot(int x, int y)
{
	double	val;
	double	val2;
	int		color;

	color = 0;
	val = (double)screen_hhalf * sin(PI * x / 180.0);
	val2 = (double)screen_hhalf * cos(PI * x / 180.0);
	if (y - screen_hhalf < val + 1 && y - screen_hhalf > val - 1)
		color |= 0x00FF0000;
	if (y - screen_hhalf < val2 + 1 && y - screen_hhalf > val2 - 1)
		color |= 0x0000FF00;
	if (y - screen_hhalf > -val - 1 && y - screen_hhalf < -val + 1)
		color |= 0x000000FF;
	if (y - screen_hhalf < 0.5 && y - screen_hhalf > -0.5)
		color |= 0x00FFFFFF;
	return (color);
}
void	get_frametime(void)
{
	static int	frame = 0;
	static clock_t	past = 0;
	static clock_t	now = 0;
	float	frametime;
	float	fps;
	
	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	fps = (float)CLOCKS_PER_SEC / (now - past);
	past = now;
//	if (frame % 10 == 0)
		printf("fps = %10.2f\t frametime = %10.4f\n", fps, frametime);
	++frame;
}
