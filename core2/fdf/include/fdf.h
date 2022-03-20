/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:26:20 by hseong            #+#    #+#             */
/*   Updated: 2022/03/20 20:23:29 by hseong           ###   ########.fr       */
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

# define SCREEN_WIDTH (768)
# define SCREEN_HEIGHT (512)
# define PI (3.141592)

# define TRUE (1)
# define FALSE (0)

typedef int				t_bool;
typedef unsigned char	t_byte;

typedef struct s_mlxinfo
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_arr;
	int		depth;
	int		line_size;
	int		endian;
	size_t	pixels;
	int		hor_size;
	int		ver_size;
}						t_mlxinfo;

int	key_hook(int keycode, void *param);

#endif
