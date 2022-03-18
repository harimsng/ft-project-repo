/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/03/18 22:07:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_loop(void *param);

int	main(int argc, char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_arr;
	int		depth = 32;
	int		endian = 0;
	int		line_size = SCREEN_WIDTH * depth;
	t_args	loop_args;

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (win_ptr == NULL)
		return (2);
	img_ptr = mlx_new_image(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img_arr = (int *)mlx_get_data_addr(img_ptr, &depth, &line_size, &endian);
	write(2, "starts\n", 7);
	loop_args = (t_args){mlx_ptr, win_ptr, img_ptr, img_arr, 1, 1};
	mlx_loop_hook(mlx_ptr, fdf_loop, &loop_args);
	mlx_loop(mlx_ptr);
	return (0);
}

int	fdf_loop(void *param)
{
	static int	frame = 0;
	int	idx;
	int	jdx;
	t_args	*args = param;
	int	*img_arr = args->img_arr;

	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img_ptr, 1, 1);
	jdx = 0;
	write(2, ".", 1);
	while (jdx < SCREEN_HEIGHT)
	{
		idx = 0;
		while (idx < SCREEN_WIDTH)
		{
			if ((5 * idx + frame) % SCREEN_WIDTH == jdx)
				img_arr[idx + SCREEN_WIDTH * jdx] = 0x00FFFFFF;
			else if (idx == (5 * jdx + frame) % SCREEN_WIDTH)
				img_arr[idx + SCREEN_WIDTH * jdx] = 0x00FFFFFF;
			else
				img_arr[idx + SCREEN_WIDTH * jdx] = 0x00000001;
			++idx;
		}
		++jdx;
	}
	++frame;
	return (0);
}
