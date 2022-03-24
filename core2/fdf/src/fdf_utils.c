/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:12:02 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 21:16:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# include <time.h>
# include <stdio.h>

void	swap_point(t_point **p0, t_point **p1)
{
	t_point	*temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}

void	get_frametime(void)
{
	static int	frame;
	static clock_t	past;
	static clock_t	now;
	float	frametime;
	float	fps;

	now = clock();
	frametime = (float)(now - past) / CLOCKS_PER_SEC;
	fps = (float)CLOCKS_PER_SEC / (now - past);
	past = now;
//	if (frame % 10 == 0)
		printf("fps = %10.2f\t frametime = %10.4f\n", fps, frametime);
	++frame;
}
