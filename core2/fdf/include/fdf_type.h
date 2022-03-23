/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:06:22 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 20:25:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPE_H
# define FDF_TYPE_H

# include <unistd.h>

typedef int				t_pixel;
typedef int				t_bool;
typedef unsigned char	t_byte;
typedef unsigned int	t_uint32;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	t_uint32	color;
}						t_point;

typedef struct s_map
{
	t_point	**map;
	int		row;
	int		col;
	int		colored;
	int		dx;
	int		dz;
}						t_map;

typedef struct s_img_elem
{
	t_pixel	*img_arr;
	int		depth_bits;
	int		line_bytes;
	int		endian;
	size_t	arr_bytes;
	size_t	hor_size;
	size_t	ver_size;
}						t_img_elem;

typedef struct s_mlx_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img_elem	*img_elem;
	t_map		*map;
}						t_mlx_info;

#endif
