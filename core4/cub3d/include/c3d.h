/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:26:20 by hseong            #+#    #+#             */
/*   Updated: 2022/05/22 22:41:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "c3d_type.h"
# include "c3d_const.h"

// mlx & map initialization
int		init_win(t_mlx_info *mlx_info);
int		init_img(t_mlx_info *mlx_info, t_img_elem *img_elem);
int		init_sub(t_mlx_info *mlx_info);
int		c3d_load_map(int argc, char **argv, t_map_info *map_info);
int		c3d_load_texture(const char **path, t_mlx_info *mlx_info);
void	c3d_exit(int status, t_mlx_info *mlx_info);
t_bool	c3d_alloc_map(t_map_info *map_info);

// update & plot functions
int		c3d_detect_wall(t_map_info *map_info, t_camera *camera, t_vec2 *point);
void	c3d_raycast(t_mlx_info *mlx_info, t_camera *camera);
void	c3d_raycast_overview(t_mlx_info *mlx_info, t_camera *camera);
void	c3d_background(t_mlx_info *mlx_info);
void
c3d_draw_vline(t_mlx_info *mlx_info, t_camera *camera, int count, double dist);
void	c3d_fill_floor(t_mlx_info *mlx_info, t_pixel *img_buf);
void	c3d_drawline(t_img_elem *img_elem, t_vec4 *p0, t_vec4 *p1);
void	c3d_aa_drawline(t_img_elem *img_elem, t_vec4 *p0, t_vec4 *p1);
void	c3d_interface(t_mlx_info *t_mlx_info);


// hook functions
int		key_hook(int keycode, void *param);
int		expose_hook(void *param);

// utility functions
t_pixel	get_color(const char *str);
t_pixel	add_color(t_pixel p0, t_pixel p1);
double	get_z_coord(char *s);
void	swap_point(t_vec4 **p0, t_vec4 **p1);
char	*get_next_line(int fd);
void	get_frametime(t_mlx_info *mlx_info, t_map_info *map_info);
double	c3d_modf(double num);
void	c3d_debug(t_mlx_info *mlx_info);
void	c3d_mouse_get_pos(t_mlx_info *mlx_info, int *x, int *y);
int		c3d_detect_collision(t_camera *camera, t_mlx_info *mlx_info);
double	vec2_dist(t_vec2 *p0, t_vec2 *p1);

#endif
