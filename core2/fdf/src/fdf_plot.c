/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:49:08 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 21:50:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_update(t_img_elem *img_elem)
{
	static int	frame;
	t_pixel		*img_arr;
	int			idx;
	int			x;
	int			y;

	img_arr = img_elem->img_arr;
	idx = 0;
	y = 0;
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
