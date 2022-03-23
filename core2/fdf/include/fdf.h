/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:26:20 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 20:47:27 by hseong           ###   ########.fr       */
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

// initialization
int			init_win(t_mlx_info *mlx_info);
int			init_img(t_mlx_info *mlx_info, t_img_elem *img_elem);

// utility functions
t_uint32	get_color(char *str);
void		swap_point(t_point **p0, t_point **p1);
char		*get_next_line(int fd);
void		get_frametime(void);

// plotting functions
int			fdf_loop(t_mlx_info *mlx_info);
int			fdf_plot(int x, int y);
void		fdf_drawline(t_img_elem *img_elem, t_point *p0, t_point *p1);
t_bool		fdf_parse_map(int argc, char **argv, t_map *map);
void		fdf_wireframe(t_img_elem *img_elem, t_map *map);
void		fdf_projection(t_mlx_info *mlx_info);

// hook functions
int			key_hook(int keycode, void *param);

#endif
