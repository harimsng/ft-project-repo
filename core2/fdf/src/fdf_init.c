/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:54:03 by hseong            #+#    #+#             */
/*   Updated: 2022/03/26 15:19:51 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_win(t_mlx_info *mlx_info)
{
	ft_putstr_fd("initializing mlx window and image...\n", 1);
	mlx_info->mlx_ptr = mlx_init();
	if (mlx_info->mlx_ptr == NULL)
		return (1);
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (mlx_info->win_ptr == NULL)
		return (2);
	mlx_info->img_ptr = mlx_new_image(mlx_info->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mlx_info->img_ptr == NULL)
		return (4);
	return (0);
}

int	init_img(t_mlx_info *mlx_info, t_img_elem *img_elem)
{
	ft_putstr_fd("allocating image space...\n", 1);
	img_elem->img_arr = (t_pixel *)mlx_get_data_addr(mlx_info->img_ptr,
			&img_elem->depth_bits, &img_elem->line_bytes, &img_elem->endian);
	if (img_elem->img_arr == NULL)
		return (8);
	if (img_elem->line_bytes != img_elem->depth_bits / 8 * SCREEN_WIDTH)
	{
		ft_putstr_fd("warning: padding exists on image memory\n", 2);
		ft_putstr_fd(" screen width = ", 2);
		ft_putnbr_fd(SCREEN_WIDTH, 2);
		ft_putstr_fd("\n line_bytes = ", 2);
		ft_putnbr_fd(img_elem->line_bytes * 8 / img_elem->depth_bits, 2);
		ft_putstr_fd("\n", 2);
	}
	if (img_elem->line_bytes % img_elem->depth_bits != 0)
	{
		ft_putstr_fd("error: wrong padding size", 2);
		return (16);
	}
	if (img_elem->depth_bits != 32)
		ft_putstr_fd("warning: depth is not 32 bits", 2);
	img_elem->hor_size = img_elem->line_bytes * 8 / img_elem->depth_bits;
	img_elem->ver_size = SCREEN_HEIGHT;
	img_elem->arr_bytes = img_elem->line_bytes * img_elem->ver_size;
	return (0);
}
