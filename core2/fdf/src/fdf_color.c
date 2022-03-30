/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:15:46 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 20:19:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

//	bit masks for bad color
//	red &= 0xFF;
//	green &= 0xFF;
//	blue &= 0xFF;
t_pixel	grade_color(t_pixel p0, t_pixel p1, double ratio)
{
	t_pixel	red;
	t_pixel	green;
	t_pixel	blue;

	if (ratio > 0.99)
		ratio = 0.99;
	else if (ratio < 0.01)
		ratio = 0.01;
	red = ((ratio * (p1 >> 16 & 0xFF))
			+ (1.0 - ratio) * (p0 >> 16 & 0xFF));
	green = ((ratio * (p1 >> 8 & 0xFF))
			+ (1.0 - ratio) * (p0 >> 8 & 0xFF));
	blue = ((ratio * (p1 & 0xFF))
			+ (1.0 - ratio) * (p0 & 0xFF));
	red <<= 16;
	green <<= 8;
	return (red + green + blue);
}

t_pixel	grade_color_aa(t_pixel p0, t_pixel p1, double ratio, double bright)
{
	t_pixel	red;
	t_pixel	green;
	t_pixel	blue;

	if (ratio > 0.99)
		ratio = 0.99;
	else if (ratio < 0.01)
		ratio = 0.01;
	red = ((ratio * (p1 >> 16 & 0xFF))
			+ (1.0 - ratio) * (p0 >> 16 & 0xFF)) * bright;
	green = ((ratio * (p1 >> 8 & 0xFF))
			+ (1.0 - ratio) * (p0 >> 8 & 0xFF)) * bright;
	blue = ((ratio * (p1 & 0xFF))
			+ (1.0 - ratio) * (p0 & 0xFF)) * bright;
	red &= 0xFF;
	green &= 0xFF;
	blue &= 0xFF;
	red <<= 16;
	green <<= 8;
	return (red + green + blue);
}

t_pixel	get_color(char *str)
{
	static t_bool	colored;
	t_uint32		temp;

	if (str == NULL)
		return (colored);
	while (*str >= '0' && *str <= '9')
		++str;
	if (*str == 0 || *str != ',')
		return (0x00FFFFFF);
	temp = ft_htoi(str + 1);
	if (temp != 0xFFFFFF)
		colored = TRUE;
	return (temp);
}
