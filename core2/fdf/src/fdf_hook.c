/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:42:44 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 22:01:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	expose_hook(void *param)
{
	t_mlx_info	*mlx_info = param;

	ft_memset(mlx_info->img_elem->img_arr, 0, mlx_info->img_elem->arr_bytes);
	return (0);
}
