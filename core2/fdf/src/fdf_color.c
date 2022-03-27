/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:15:46 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 21:27:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_pixel	add_color(t_pixel p0, t_pixel p1)
{
	return (((((p0 & 0xFF0000) >> 17) + ((p1 & 0xFF0000) >> 17)) << 17)
	+ ((((p0 & 0xFF00) >> 9) + ((p1 & 0xFF00) >> 9)) << 9)
	+ (((p0 & 0xFF >> 1) + ((p1 & 0xFF >> 1))) << 1));
}
*/

t_pixel	grade_color(t_pixel p0, t_pixel p1, double ratio, double bright)
{
	t_pixel	red;
	t_pixel	green;
	t_pixel	blue;

	ratio += 0.01 * (ratio <= 0.01);
//	bright += 0.0001 * ((bright <= 0.001) - (bright >= 0.999));
	red = (ratio * bright * (p1 >> 16 & 0xFF))
		+ (1.0 - ratio) * bright * (p0 >> 16 & 0xFF);
	green = (ratio * bright * (p1 >> 8 & 0xFF))
		+ (1.0 - ratio) * bright * (p0 >> 8 & 0xFF);
	blue = (ratio * bright * (p1 & 0xFF))
		+ (1.0 - ratio) * bright * (p0 & 0xFF);
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
	{
		colored = TRUE;
		return (0x00FFFFFF);
	}
	temp = ft_htoi(str + 1);
	if (temp == 0xFFFFFF)
		colored = TRUE;
	return (temp);
}
