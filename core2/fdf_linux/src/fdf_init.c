/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:54:03 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 22:32:00 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int	init_win(t_mlx_info *mlx_info)
{
	ft_putstr_fd("initializing mlx window and image\n", 1);
	mlx_info->mlx_ptr = mlx_init();
	if (mlx_info->mlx_ptr == NULL)
		return (0x10);
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT + SUBIMG_HEIGHT, "fdf");
	if (mlx_info->win_ptr == NULL)
		return (0x20);
	mlx_info->img_ptr = mlx_new_image(mlx_info->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (mlx_info->img_ptr == NULL)
		return (0x40);
	return (0);
}

int	init_img(t_mlx_info *mlx_info, t_img_elem *img_elem)
{
	ft_putstr_fd("allocating image space\n", 1);
	img_elem->img_buf = (t_pixel *)mlx_get_data_addr(mlx_info->img_ptr,
			&img_elem->depth_bits, &img_elem->line_bytes, &img_elem->endian);
	if (img_elem->img_buf == NULL)
		return (0x80);
	if (img_elem->line_bytes != img_elem->depth_bits / 8 * SCREEN_WIDTH)
		ft_putstr_fd("warning: padding exists on image memory\n", 2);
	if (img_elem->endian == 1)
		ft_putstr_fd("warning: big endian: memory error may occurs\n", 2);
	if (img_elem->line_bytes % img_elem->depth_bits != 0)
	{
		ft_putstr_fd("error: wrong padding size", 2);
		return (0x100);
	}
	if (img_elem->depth_bits != 32)
		ft_putstr_fd("warning: depth != 32 bits. memory error may occurs\n", 2);
	img_elem->hor_px = img_elem->line_bytes * 8 / img_elem->depth_bits;
	img_elem->ver_px = SCREEN_HEIGHT;
	img_elem->arr_bytes = img_elem->line_bytes * img_elem->ver_px;
	return (0);
}

int	init_sub(t_mlx_info *mlx_info)
{
	t_img_elem	*sub_elem;

	sub_elem = mlx_info->sub_elem ;
	ft_putstr_fd("allocating sub-image space\n", 1);
	mlx_info->sub_ptr = mlx_new_image(mlx_info->mlx_ptr,
			SUBIMG_WIDTH, SUBIMG_HEIGHT);
	if (mlx_info->sub_ptr == NULL)
		return (0x200);
	sub_elem->img_buf = (t_pixel *)mlx_get_data_addr(mlx_info->sub_ptr,
			&sub_elem->depth_bits, &sub_elem->line_bytes, &sub_elem->endian);
	if (sub_elem->img_buf == NULL)
		return (0x400);
	sub_elem->hor_px = sub_elem->line_bytes * 8 / sub_elem->depth_bits;
	sub_elem->ver_px = SUBIMG_HEIGHT;
	sub_elem->arr_bytes = sub_elem->line_bytes * sub_elem->ver_px;
	return (0);
}
