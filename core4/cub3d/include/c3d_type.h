/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:03:29 by hseong            #+#    #+#             */
/*   Updated: 2022/05/24 01:02:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_TYPE_H
# define C3D_TYPE_H

# include <unistd.h>
//# include <pthread.h>
# include "c3d_const.h"

typedef unsigned int	t_pixel;
typedef int				t_bool;
typedef unsigned char	t_byte;
typedef unsigned int	t_uint32;
typedef long long int	t_int64;

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_ivec2
{
	t_int64	x;
	t_int64	y;
}			t_ivec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	t_pixel	color;
}			t_vec4;

typedef struct s_camera
{
	double	angle;
	double	x;
	double	y;
}			t_camera;

typedef struct s_map_info
{
	int		**map;
	size_t	row;
	size_t	col;
}			t_map_info;

/*
typedef struct s_mouse
{
	int	x;
	int	y;
}			t_mouse;
*/

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

typedef struct s_resource
{
	void		*texture_arr[MAX_TEXTURE];
	t_img_elem	attr_arr[MAX_TEXTURE];
	int			size;
}			t_resource;

typedef struct s_mlx_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*sub_ptr;
	t_img_elem	*img_elem;
	t_map_info	*map_info;
	t_resource	*resource;
	t_camera	*camera;
//	pthread_t	thread[SCREEN_HEIGHT];
}			t_mlx_info;

#endif
