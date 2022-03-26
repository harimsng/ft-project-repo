/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:26:20 by hseong            #+#    #+#             */
/*   Updated: 2022/03/26 20:52:08 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "fdf_type.h"
# include "fdf_const.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
#include <stdio.h>

// mlx & map initialization
int			init_win(t_mlx_info *mlx_info);
int			init_img(t_mlx_info *mlx_info, t_img_elem *img_elem);
t_bool		fdf_load_map(int argc, char **argv, t_map *map);
void		fdf_align_map(t_map *map);

// update & plot functions
void		fdf_update(t_img_elem *img_elem);
void		fdf_plot(int x, int y, double color, t_img_elem *img_elem);
void		fdf_drawline(t_img_elem *img_elem, t_point *p0, t_point *p1);
void		fdf_aa_drawline(t_img_elem *img_elem, t_point *p0, t_point *p1);
void		fdf_wireframe(t_img_elem *img_elem, t_map *map);
void		fdf_projection(t_mlx_info *mlx_info);
void		fdf_control_map(t_map *map);

// hook functions
int			key_hook(int keycode, void *param);
int			expose_hook(void *param);

// utility functions
t_uint32	get_color(char *str);
void		swap_point(t_point **p0, t_point **p1);
char		*get_next_line(int fd);
void		get_frametime(void);

#endif
