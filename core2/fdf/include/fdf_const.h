/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:04 by hseong            #+#    #+#             */
/*   Updated: 2022/03/31 22:29:02 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONST_H
# define FDF_CONST_H

// screen constants
# define SCREEN_WIDTH (1920)
# define SCREEN_HEIGHT (1080)
# define VP_DIST (500) // viewport distance
# define SUBIMG_WIDTH (SCREEN_WIDTH)
# define SUBIMG_HEIGHT (80)
# define TEXT_HEIGHT (16)

// map control coefficient
# define X_STEP (8)
# define Y_STEP (8)
# define YAW_STEP (0.08)
# define ROLL_STEP (0.08)
# define PITCH_STEP (0.08)
# define SCALE_STEP (1.2) 

// maximum map size
# define MAP_MAXROWS (2048)
# define MAP_MAXCOLS (2048)

// default angles
# define HOR_ANGLE (0.7853) // PI / 4 ~= 0.7853
# define VER_ANGLE (0.5236) // PI / 6 ~= 0.5236
# define GAMMA (0.0)

# define TRUE (1)
# define FALSE (0)

# define BYTE (0xFF)

static const int	g_screen_hwidth = SCREEN_WIDTH / 2;
static const int	g_screen_hheight = SCREEN_HEIGHT / 2;

#endif
