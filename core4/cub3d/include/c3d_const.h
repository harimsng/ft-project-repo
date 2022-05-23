/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:04 by hseong            #+#    #+#             */
/*   Updated: 2022/05/24 05:02:23 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_CONST_H
# define C3D_CONST_H

// environment constant
# define SCREEN_WIDTH (1920)
# define SCREEN_HEIGHT (1280)
# define VP_DIST (256) // viewport distance
# define SUBIMG_WIDTH (SCREEN_WIDTH)
# define SUBIMG_HEIGHT (80)
# define TEXT_HEIGHT (16)
# define MAX_TEXTURE (16)

// map control coefficient
# define FOV (75.0)
# define MOUSE_SENSITIVITY (0.002)
# define GRID_WIDTH (64)
# define MASK_GRID_WIDTH (63)	// if grid_width = 2^n, mask = grid_width - 1
# define LOG_GRID_WIDTH (6)		// log2(grid_width)
# define X_STEP (3)
# define Y_STEP (3)
# define YAW_STEP (0.1)
# define MAX_DIST (800)
# define LIGHT_DIST (400)

// maximum map size
# define MAP_MAXROWS (2048)
# define MAP_MAXCOLS (2048)

# define TRUE (1)
# define FALSE (0)

enum e_return
{
	SUCCESS,
	FAIL
};

# define BYTE (0xFF)

static const int	g_screen_hwidth = SCREEN_WIDTH / 2;
static const int	g_screen_hheight = SCREEN_HEIGHT / 2;

#endif
