/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:04 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 06:43:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_CONST_H
# define C3D_CONST_H

# define SCREEN_WIDTH (1280)
# define SCREEN_HEIGHT (1280)
# define VP_DIST (500) // viewport distance
# define SUBIMG_WIDTH (SCREEN_WIDTH)
# define SUBIMG_HEIGHT (80)
# define TEXT_HEIGHT (16)

// map control coefficient
# define FOV (60.0)
# define GRID_WIDTH (128)
# define X_STEP (8)
# define Y_STEP (8)
# define YAW_STEP (0.5);

// maximum map size
# define MAP_MAXROWS (2048)
# define MAP_MAXCOLS (2048)

# define TRUE (1)
# define FALSE (0)

# define BYTE (0xFF)

static const int	g_screen_hwidth = SCREEN_WIDTH / 2;
static const int	g_screen_hheight = SCREEN_HEIGHT / 2;

#endif
