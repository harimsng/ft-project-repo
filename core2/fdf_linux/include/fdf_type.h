/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:03:29 by hseong            #+#    #+#             */
/*   Updated: 2022/04/13 13:09:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPE_H
# define FDF_TYPE_H

# include <unistd.h>
# include <pthread.h>
# include "fdf_const.h"

typedef unsigned int	t_pixel;
typedef int				t_bool;
typedef unsigned char	t_byte;
typedef unsigned int	t_uint32;

typedef struct s_mouse
{
	int	x;
	int	y;
}			t_mouse;

typedef struct s_vertex
{
	double	x;
	double	y;
	double	z;
	t_pixel	color;
}			t_vertex;

typedef struct s_map_info
{
	t_vertex	**map_proj;
	t_vertex	**map_origin;
	int			x0;
	int			y0;
	int			row;
	int			col;
	double		hor_scale;
	double		ver_scale;
	double		fract_scale;
	double		hor_angle;
	double		ver_angle;
	double		gamma;
	double		var_x;
	double		var_y;
	int			var_height;
	int			max_height;
	int			projection;
	t_bool		arg_flag;
	t_bool		colored_flag;
}				t_map_info;

typedef struct s_mlx_flag
{
	t_bool		wireframe_flag;
	t_bool		background_flag;
	t_bool		interface_flag;
	t_bool		automove_flag;
}			t_mlx_flag;

typedef struct s_img_elem
{
	t_pixel	*img_buf;
	int		depth_bits;
	int		line_bytes;
	int		endian;
	size_t	arr_bytes;
	size_t	hor_px;
	size_t	ver_px;
}			t_img_elem;

typedef struct s_mlx_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*sub_ptr;
	t_img_elem	*img_elem;
	t_img_elem	*sub_elem;
	t_map_info	*map_info;
	t_mlx_flag	*mlx_flag;
	pthread_t	thread[SCREEN_HEIGHT];
}				t_mlx_info;

#endif
