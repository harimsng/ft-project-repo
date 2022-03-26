/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aa_drawline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:06:03 by hseong            #+#    #+#             */
/*   Updated: 2022/03/26 21:35:12 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	aa_drawline_low(t_img_elem *img_elem, t_point p0, t_point p1);
static void	aa_drawline_high(t_img_elem *img_elem, t_point p0, t_point p1);

void	fdf_aa_drawline(t_img_elem *img_elem, t_point *p0, t_point *p1)
{
	int		dx;
	int		dy;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dx < 0)
		swap_point(&p0, &p1);
	if (ft_abs(dx) > ft_abs(dy))
		aa_drawline_low(img_elem, *p0, *p1);
	else
		aa_drawline_high(img_elem, *p0, *p1);
}

void	aa_drawline_low(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int			idx;
	int			idx2;
	int			ix0;
	int			iy0;
	int			ix1;
	int			iy1;
	double		dx;
	double		dy;
	double		dydx;
	double		dummy;
	double		coeff;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	dydx = dy / dx;
	ix0 = lround(p0.x);
	iy0 = lround(p0.y);
	ix1 = lround(p1.x);
	iy1 = lround(p1.y);
	while (ix0 < ix1)
	{
		idx = lround(p0.y) * img_elem->hor_size + ix0;
		idx2 = lround(p0.y + 1.0) * img_elem->hor_size + ix0;
		coeff = modf(p0.y, &dummy);
		if (ix0 >= 0 && ix0 < SCREEN_WIDTH && (int)iy0 >= 0 && (int)iy0 < SCREEN_HEIGHT - 1)
		{
		img_elem->img_arr[idx2] = (int)(0xFE * (1.0 - coeff)) * 0x00010101;//p0.color;
		img_elem->img_arr[idx] = (int)(0xFE * coeff) * 0x00010101;//p0.color;
		}
		p0.y += dydx;
		++ix0;
		iy0 = lround(p0.y);
	}
}

void	aa_drawline_high(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int			idx;
	int			idx2;
	int			ix0;
	int			iy0;
	int			ix1;
	int			iy1;
	double		dx;
	double		dy;
	double		dxdy;
	double		sy;
	double		dummy;
	double		coeff;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	sy = 1.0;
	if (dy < 0)
		sy = -1.0;
	dxdy = dx / dy * sy;
	ix0 = floor(p0.x);
	iy0 = floor(p0.y);
	ix1 = floor(p1.x);
	iy1 = floor(p1.y);
	while (iy0 != iy1)
	{
		idx = lround(p0.x) + img_elem->hor_size * iy0;
		idx2 = lround(p0.x + sy) + img_elem->hor_size * iy0;
		coeff = modf(p0.x, &dummy);
		if (ix0 >= 0 && ix0 < SCREEN_WIDTH - 1 && (int)iy0 >= 0 && (int)iy0 < SCREEN_HEIGHT)
		{
		img_elem->img_arr[idx2] = (int)(0xFE * (1.0 - coeff)) * 0x00010101;//p0.color;
		img_elem->img_arr[idx] = (int)(0xFE * coeff) * 0x00010101;//p0.color;
		}
		p0.x += dxdy;
		iy0 += (int)sy;
		ix0 = lround(p0.x);
	}
}
