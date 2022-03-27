/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:15:46 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 18:23:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	grade_color(t_pixel p0, t_pixel p1, double ratio)
{
	t_pixel	red;
	t_pixel	green;
	t_pixel	blue;

	if (ratio <= 0.00001)
		ratio = 0.00001;
	else if (ratio >= 0.99999)
		ratio = 0.99999;
	red = ((int)(0xFF * ratio) * ((p1 & 0xFF0000) >> 16))
		+ ((int)(0xFF * (1.0 -  ratio)) * ((p0 & 0xFF0000) >> 16));
	green = ((int)(0xFF * ratio) * ((p1 & 0xFF00) >> 8))
		+ ((int)(0xFF * (1.0 - ratio)) * ((p0 & 0xFF00) >> 8));
	blue = ((int)(0xFF * ratio) * (p1 & 0xFF))
		+ ((int)(0xFF * (1.0 - ratio)) * (p0 & 0xFF));
	red &= 0xFF00;
	green &= 0xFF00;
	blue &= 0xFF00;
	red <<= 8;
	blue >>= 8;
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
