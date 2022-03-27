/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:04 by hseong            #+#    #+#             */
/*   Updated: 2022/03/27 19:26:21 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONST_H
# define FDF_CONST_H

# define SCREEN_WIDTH (1920)
# define SCREEN_HEIGHT (1080)

# define MAP_MAXROWS (1024)
# define MAP_MAXCOLS (1024)

# define MAGIC_ANGLE (0.5236)
//# define MAGIC_ANGLE (0.4636)

# define TRUE (1)
# define FALSE (0)

# define BYTE ((t_uint32)0xFF)

static const int	screen_whalf = SCREEN_WIDTH / 2;
static const int	screen_hhalf = SCREEN_HEIGHT / 2;

#endif
