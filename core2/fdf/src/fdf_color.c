/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:15:46 by hseong            #+#    #+#             */
/*   Updated: 2022/03/26 16:45:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
t_uint32	ftoi_color(double opa, double red, double green, double blue)
{
	
}
*/

t_uint32	get_color(char *str)
{
	while (*str >= '0' && *str <= '9')
		++str;
	if (*str == 0 || *str != ',')
		return (0x00FFFFFF);
	return (ft_htoi(str + 1));
}
