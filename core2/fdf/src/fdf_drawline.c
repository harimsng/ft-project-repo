/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:35:23 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 17:42:11 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	drawline_low(t_img_elem *img_elem, t_point p0, t_point p1);
static void	drawline_high(t_img_elem *img_elem, t_point p0, t_point p1);

void	fdf_drawline(t_img_elem *img_elem, t_point *p0, t_point *p1)
{
	int		dx;
	int		dy;

	dx = ft_abs(p1->x - p0->x);
	dy = ft_abs(p1->y - p0->y);
	if (p0->x > p1->x)
		swap_point(&p0, &p1);
	if (dx > dy)
		drawline_low(img_elem, *p0, *p1);
	else
		drawline_high(img_elem, *p0, *p1);
}

void	drawline_low(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		sy;
	int		diff;

	dx = p1.x - p0.x;
	sy = 1;
	if (p1.y - p0.y < 0)
		sy = -1;
	dy = ft_abs(p1.y - p0.y);
	diff = 2 * dy - dx;
	while (p0.x < p1.x)
	{
		if (p0.x < SCREEN_WIDTH && p0.x > 0
			&& p0.y > 0 && p0.y < SCREEN_HEIGHT)
			img_elem->img_arr[p0.x + img_elem->hor_size * p0.y] = p0.color;
		if (diff > 0)
		{
			diff -= dx;
			p0.y += sy;
		}
		diff += dy;
		++p0.x;
	}
}

void	drawline_high(t_img_elem *img_elem, t_point p0, t_point p1)
{
	int		dx;
	int		dy;
	int		sy;
	int		diff;

	dx = p1.x - p0.x;
	sy = 1;
	if (p1.y - p0.y < 0)
		sy = -1;
	dy = abs(p1.y - p0.y);
	diff = 2 * dx - dy;
	while (p0.y != p1.y)
	{
		if (p0.x < SCREEN_WIDTH && p0.x > 0
			&& p0.y > 0 && p0.y < SCREEN_HEIGHT)
			img_elem->img_arr[p0.x + img_elem->hor_size * p0.y] = p0.color;
		if (diff > 0)
		{
			diff -= dy;
			++p0.x;
		}
		diff += dx;
		p0.y += sy;
	}
}
