/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/03/20 20:07:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

# include <time.h>

void	*ft_memset(void *addr, int val, size_t len);
int	fdf_loop(t_mlxinfo *param);

void	get_frametime(void);

int	main(int argc, char *argv[])
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_arr;
	t_mlxinfo	mlxinfo;

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (win_ptr == NULL)
		return (2);
	img_ptr = mlx_new_image(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (img_ptr == NULL)
		return (4);
	img_arr = (int *)mlx_get_data_addr(img_ptr,
		&mlxinfo.depth, &mlxinfo.line_size, &mlxinfo.endian);
	if (img_arr == NULL)
		return (8);
	mlxinfo = (t_mlxinfo){.mlx_ptr = mlx_ptr, .win_ptr = win_ptr,
		.img_ptr = img_ptr, .img_arr = img_arr,
		.pixels = mlxinfo.line_size * SCREEN_HEIGHT};
	printf("%zu\n", mlxinfo.pixels);
	write(2, "starts\n", 7);
	mlx_key_hook(win_ptr, key_hook, NULL);
	mlx_loop_hook(mlx_ptr, fdf_loop, &mlxinfo);
	mlx_loop(mlx_ptr);
	return (0);
}

int	fdf_loop(t_mlxinfo *args)
{
	static int	frame = 0;
	t_bool		blank;
	int	idx;
	int	jdx;
	double val;
	double val2;
	int	*img_arr = args->img_arr;

	mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, args->img_ptr, 1, 1);
	get_frametime();
	ft_memset(img_arr, 0, args->pixels);
	jdx = 0;
	write(2, ".", 1);
	while (jdx < SCREEN_HEIGHT)
	{
		idx = 0;
		while (idx < SCREEN_WIDTH)
		{
			blank = TRUE;
			val = (double)SCREEN_HEIGHT / 2 * sin(PI * (idx + frame) / 180.0);
			val2 = (double)SCREEN_HEIGHT / 2 * cos(PI * (idx + frame) / 180.0);
			if (jdx - SCREEN_HEIGHT / 2 < val + 1 && jdx - SCREEN_HEIGHT / 2 > val - 1)
			{
				blank = FALSE;
				img_arr[idx + SCREEN_WIDTH * jdx] = 0x00FF0000;
				img_arr[idx + SCREEN_WIDTH * (SCREEN_HEIGHT - jdx - 1)] = 0x000000FF;
			}
			if (jdx - SCREEN_HEIGHT / 2 < val2 + 1 && jdx - SCREEN_HEIGHT / 2 > val2 - 1)
			{
				blank = FALSE;
				img_arr[idx + SCREEN_WIDTH * jdx] = 0x0000FF00;
			}
			++idx;
		}
		++jdx;
	}
	++frame;
	return (0);
}

void	get_frametime(void)
{
	static int	frame = 0;
	static clock_t	past = 0;
	static clock_t	now = 0;
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
