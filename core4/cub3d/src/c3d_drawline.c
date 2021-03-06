/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:35:23 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 19:45:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "libft.h"

static void	drawline_low_up(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1);
static void	drawline_low_down(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1);
static void	drawline_high_up(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1);
static void	drawline_high_down(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1);

void	c3d_drawline(t_img_elem *img_elem, t_vec4 *p0, t_vec4 *p1)
{
	int		dy;

	if ((int)(p1->x - p0->x) < 0)
		swap_point(&p0, &p1);
	dy = p1->y - p0->y;
	if ((t_uint32)p0->x >= SCREEN_WIDTH || (t_uint32)p0->y >= SCREEN_HEIGHT
		|| (t_uint32)p1->x >= SCREEN_WIDTH || (t_uint32)p1->y >= SCREEN_HEIGHT)
		return ;
	img_elem->img_buf[(int)p0->x + img_elem->hor_px * (int)p0->y] = p0->color;
	if ((int)(p1->x - p0->x) > ft_abs(dy))
	{
		if (dy > 0)
			drawline_low_up(img_elem, *p0, *p1);
		else
			drawline_low_down(img_elem, *p0, *p1);
	}
	else
	{
		if (dy > 0)
			drawline_high_up(img_elem, *p0, *p1);
		else
			drawline_high_down(img_elem, *p0, *p1);
	}
	img_elem->img_buf[(int)p1->x + img_elem->hor_px * (int)p1->y] = p1->color;
}

void	drawline_low_down(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p0.y - (int)p1.y;
	diff = 2 * dy - dx;
	while (++x0 < (int)p1.x)
	{
		img_elem->img_buf[x0 + img_elem->hor_px * y0] = p0.color;
		if (diff > 0)
		{
			diff -= dx;
			--y0;
		}
		diff += dy;
	}
}

void	drawline_high_down(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p0.y - (int)p1.y;
	diff = 2 * dx - dy;
	while (--y0 > (int)p1.y)
	{
		img_elem->img_buf[x0 + img_elem->hor_px * y0] = p0.color;
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}

void	drawline_low_up(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p1.y - (int)p0.y;
	diff = 2 * dy - dx;
	while (++x0 < (int)p1.x)
	{
		img_elem->img_buf[x0 + img_elem->hor_px * y0] = p0.color;
		if (diff > 0)
		{
			diff -= dx;
			++y0;
		}
		diff += dy;
	}
}

void	drawline_high_up(t_img_elem *img_elem, t_vec4 p0, t_vec4 p1)
{
	int		dx;
	int		dy;
	int		diff;
	int		x0;
	int		y0;

	x0 = p0.x;
	y0 = p0.y;
	dx = (int)p1.x - (int)p0.x;
	dy = (int)p1.y - (int)p0.y;
	diff = 2 * dx - dy;
	while (++y0 < (int)p1.y)
	{
		img_elem->img_buf[x0 + img_elem->hor_px * y0] = p0.color;
		if (diff > 0)
		{
			diff -= dy;
			++x0;
		}
		diff += dx;
	}
}
