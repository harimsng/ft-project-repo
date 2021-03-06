/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:26:20 by hseong            #+#    #+#             */
/*   Updated: 2022/04/11 18:11:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_type.h"
# include "fdf_const.h"

// mlx & map initialization
int		init_win(t_mlx_info *mlx_info);
int		init_img(t_mlx_info *mlx_info, t_img_elem *img_elem);
int		init_sub(t_mlx_info *mlx_info);
t_bool	fdf_load_map(int argc, char **argv, t_map_info *map_info);
void	fdf_setup_map(t_mlx_info *mlx_info);
void	fdf_exit(int status, t_mlx_info *mlx_info);
t_bool	fdf_alloc_map(t_map_info *map_info);

// update & plot functions
void	fdf_plot_loop(t_mlx_info *mlx_info);
void	fdf_plot(int x, int y, double brightness, t_img_elem *img_elem);
void	fdf_drawline(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1);
void	fdf_aa_drawline(t_img_elem *img_elem, t_vertex *p0, t_vertex *p1);
void	fdf_wireframe(t_img_elem *img_elem, t_map_info *map_info);
void	fdf_projection(t_map_info *map_info);
t_pixel	grade_color_aa(t_pixel p0, t_pixel p1, double ratio, double brightness);
t_pixel	grade_color(t_pixel p0, t_pixel p1, double ratio);
void	fdf_interface(t_mlx_info *t_mlx_info);

// hook functions
int		key_hook(int keycode, void *param);
int		expose_hook(void *param);

// utility functions
t_pixel	get_color(const char *str);
t_pixel	add_color(t_pixel p0, t_pixel p1);
double	get_z_coord(char *s);
void	swap_point(t_vertex **p0, t_vertex **p1);
char	*get_next_line(int fd);
void	get_frametime(t_mlx_info *mlx_info, t_map_info *map_info);
double	fdf_modf(double num);
void	fdf_debug(t_mlx_info *mlx_info);

#endif
