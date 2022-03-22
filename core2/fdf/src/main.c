/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:18:38 by hseong            #+#    #+#             */
/*   Updated: 2022/03/22 19:45:01 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_mlx_info	mlx_info;
	t_img_elem	img_elem;
	t_map		map;

	if (fdf_parser(argc, argv, &map) == NULL)
		ft_putstr_fd("invalid map format\n", 2);
	img_elem.map = &map;
	if (init_win(&mlx_info) != 0
		|| init_img(&mlx_info, &img_elem) != 0)
	{
		perror("initialization failed");
		exit(1);
	}
	mlx_key_hook(mlx_info.win_ptr, key_hook, NULL);
	mlx_loop_hook(mlx_info.mlx_ptr, fdf_loop, &mlx_info);
	mlx_loop(mlx_info.mlx_ptr);
	return (0);
}
