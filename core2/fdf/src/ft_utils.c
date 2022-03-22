/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:13:50 by hseong            #+#    #+#             */
/*   Updated: 2022/03/22 17:28:59 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_type.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
}

void	ft_swap_points(t_point **p0, t_point **p1)
{
	t_point	*temp;

	temp = *p0;
	*p0 = *p1;
	*p1 = temp;
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
