/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aa_drawline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:06:03 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 18:52:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		aa_drawline_low(t_img_elem *img_elem, t_vertex p0, t_vertex p1);
static void		aa_drawline_high(t_img_elem *img_elem, t_vertex p0, t_vertex p1);
static double	fdf_modf(double num);

void	fdf_aa_drawline(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1)
{
	int		dx;
	int		dy;

	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (ft_abs(dx) > ft_abs(dy))
		aa_drawline_low(img_elem, *p0, *p1);
	else
	{
		if (dy < 0)
			aa_drawline_high(img_elem, *p1, *p0);
		else
			aa_drawline_high(img_elem, *p0, *p1);
	}
}

void	aa_drawline_low(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
{
	int			idx;
	int			ix0;
	int			iy0;
	double		dydx;
	double		coeff;

	dydx = (p1.y - p0.y) / (p1.x - p0.x);
	ix0 = p0.x;
	iy0 = p0.y;
	while (ix0 <= (int)p1.x)
	{
		if ((t_uint32)ix0 >= SCREEN_WIDTH
			|| (t_uint32)iy0 >= SCREEN_HEIGHT - 1)
			break ;
		idx = (int)(p0.y) * img_elem->hor_size + ix0;
		coeff = fdf_modf(p0.y);
		img_elem->img_arr[idx] =// (int)(0xFF * (1.0 - coeff))
				grade_color(p0.color, p1.color, (ix0 - p0.x) / (p1.x - p0.x));
		img_elem->img_arr[idx + img_elem->hor_size] =// (int)(0xFF * coeff)
				grade_color(p0.color, p1.color, (ix0 - p0.x) / (p1.x - p0.x));
		p0.y += dydx;
		++ix0;
		iy0 = (int)p0.y;
	}
}

void	aa_drawline_high(t_img_elem *img_elem, t_vertex p0, t_vertex p1)
{
	int			idx;
	int			ix0;
	int			iy0;
	double		dxdy;
	double		coeff;

	dxdy = (p1.x - p0.x) / (p1.y - p0.y);
	ix0 = p0.x;
	iy0 = p0.y;
	while (iy0 <= (int)p1.y)
	{
		if ((t_uint32)ix0 >= SCREEN_WIDTH - 1
			|| (t_uint32)iy0 >= SCREEN_HEIGHT)
			break ;
		idx = (int)(p0.x) + img_elem->hor_size * iy0;
		coeff = fdf_modf(p0.x);
		img_elem->img_arr[idx] =// (int)(0xFF * (1.0 - coeff))
				grade_color(p0.color, p1.color, (iy0 - p0.y) / (p1.y - p0.y));
		img_elem->img_arr[idx + 1] =// (int)(0xFF * coeff)
				grade_color(p0.color, p1.color, (iy0 - p0.y) / (p1.y - p0.y));
		p0.x += dxdy;
		++iy0;
		ix0 = (int)p0.x;
	}
}

static double	fdf_modf(double num)
{
	return (num - floor(num));
}
