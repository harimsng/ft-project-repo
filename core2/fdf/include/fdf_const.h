/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:10:04 by hseong            #+#    #+#             */
/*   Updated: 2022/03/24 17:29:24 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONST_H
# define FDF_CONST_H

# define SCREEN_WIDTH (768)
# define SCREEN_HEIGHT (512)

# define MAP_MAXROWS (1024)
# define MAP_MAXCOLS (1024)

# define MAGIC_ANGLE (0.615479708)

# define TRUE (1)
# define FALSE (0)

static const int	screen_whalf = SCREEN_WIDTH / 2;
static const int	screen_hhalf = SCREEN_HEIGHT / 2;

#endif
