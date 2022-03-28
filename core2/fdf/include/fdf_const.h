/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:04 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 20:43:32 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONST_H
# define FDF_CONST_H

# define SCREEN_WIDTH (1920)
# define SCREEN_HEIGHT (1080)

# define TEXT_HEIGHT (50)

# define X_STEP (6)
# define Y_STEP (6)
# define YAW_STEP (0.1)
# define ROLL_STEP (0.1)
# define SCALE_STEP (2) 

# define MAP_MAXROWS (1024)
# define MAP_MAXCOLS (1024)

# define HOR_ANGLE (0.7853) // PI / 4
# define VER_ANGLE (0.5236) // PI / 6
//# define MAGIC_ANGLE (0.4636)

# define TRUE (1)
# define FALSE (0)

# define BYTE ((t_uint32)0xFF)

static const int	screen_whalf = SCREEN_WIDTH / 2;
static const int	screen_hhalf = SCREEN_HEIGHT / 2;

#endif
