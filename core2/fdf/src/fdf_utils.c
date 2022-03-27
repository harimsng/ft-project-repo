/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:12:02 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 18:17:20 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <time.h>
# include <stdio.h>

void	swap_point(t_vertex **p0, t_vertex **p1)
{
	t_vertex	*temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}

void	get_frametime(void)
{
	static int		frame;
	static clock_t	past;
	static clock_t	now;
	float			frametime;
	float			fps;

	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	fps = (float)CLOCKS_PER_SEC / (now - past);
	past = now;
	if (frame % 20 == 0)
		printf("frame = %10d, fps = %10.2f\t frametime = %10.4f\n", frame, fps, frametime);
	++frame;
}

double	get_z_coord(char *s)
{
	static double	max_z;
	double			z;

	if (s == NULL)
		return (max_z);
	z = (double)ft_atoi(s);
	if (z > max_z)
		max_z = z;
	return (z);
}
