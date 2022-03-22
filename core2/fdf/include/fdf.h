/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:26:20 by hseong            #+#    #+#             */
/*   Updated: 2022/03/22 16:10:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define SCREEN_WIDTH (800)
# define SCREEN_HEIGHT (600)
# define PI (3.141592)

# define TRUE (1)
# define FALSE (0)

static const int	screen_whalf = SCREEN_WIDTH / 2;
static const int	screen_hhalf = SCREEN_HEIGHT / 2;

typedef int				t_pixel;
typedef int				t_bool;
typedef unsigned char	t_byte;

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
}						t_mlx_info;

int		fdf_loop(t_mlx_info *mlx_info);
int		fdf_plot(int x, int y);
void	fdf_drawline(t_img_elem *img_elem, int x0, int y0, int x1, int y1);

// hook functions
int		key_hook(int keycode, void *param);

// libft functions
void	*ft_memset(void *addr, int val, size_t size);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_swap(int *a, int *b);
int		ft_abs(int a);

#endif
