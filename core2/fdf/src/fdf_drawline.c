/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:35:23 by hseong            #+#    #+#             */
/*   Updated: 2022/03/22 16:08:14 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawline_low(t_img_elem *img_elem, int x0, int y0, int x1, int y1);
static void	drawline_high(t_img_elem *img_elem, int x0, int y0, int x1, int y1);

void	fdf_drawline(t_img_elem *img_elem, int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;

	dx = ft_abs(x1 - x0);
	dy = ft_abs(y1 - y0);
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	if (dx > dy)
		drawline_low(img_elem, x0, y0, x1, y1);
	else
		drawline_high(img_elem, x0, y0, x1, y1);
}

void	drawline_low(t_img_elem *img_elem, int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		sy;
	int		diff;

	dx = x1 - x0;
	sy = 1;
	if (y1 - y0 < 0)
		sy = -1;
	dy = ft_abs(y1 - y0);
	diff = 2 * dy - dx;
	while (x0 < x1)
	{
		img_elem->img_arr[x0 + img_elem->hor_size * y0] = 0x00FFFFFF;
		if (diff > 0)
		{
			diff -= dx;
			y0 += sy;
		}
		diff += dy;
		++x0;
	}
}

void	drawline_high(t_img_elem *img_elem, int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		sy;
	int		diff;

	dx = x1 - x0;
	sy = 1;
	if (y1 - y0 < 0)
		sy = -1;
	dy = abs(y1 - y0);
	diff = 2 * dx - dy;
	while (y0 != y1)
	{
		img_elem->img_arr[x0 + img_elem->hor_size * y0] = 0x00FFFFFF;
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
		y0 += sy;
	}
}
