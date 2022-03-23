/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:26:20 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 19:12:52 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "fdf_type.h"
# include "fdf_const.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

// initialization
int		init_win(t_mlx_info *mlx_info);
int		init_img(t_mlx_info *mlx_info, t_img_elem *img_elem);

// color control functions
int		get_color(char *str);

// plotting functions
int		fdf_loop(t_mlx_info *mlx_info);
int		fdf_plot(int x, int y);
void	fdf_drawline(t_img_elem *img_elem, t_point *p0, t_point *p1);
t_bool	fdf_parse_map(int argc, char **argv, t_map *map);

// hook functions
int		key_hook(int keycode, void *param);

// libft functions
void	*ft_memset(void *addr, int val, size_t size);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_swap_points(t_point **p0, t_point **p1);
int		ft_abs(int a);
char	**ft_split(char *str, char *delim);
int		ft_atoi(const char *str);
char	*get_next_line(int fd);

#endif
