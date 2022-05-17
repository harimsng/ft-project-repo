/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keymap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:57 by hseong            #+#    #+#             */
/*   Updated: 2022/05/18 06:29:43 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_KEYMAP_H
# define C3D_KEYMAP_H

# include "c3d_type.h"
# include "c3d_const.h"

typedef void			(*t_key_func)(t_mlx_info *mlx_info);

void	dummy_func(t_mlx_info *mlx_info);
void	exit_program(t_mlx_info *mlx_info);

void	move_obj_left(t_mlx_info *mlx_info);
void	move_obj_right(t_mlx_info *mlx_info);
void	move_obj_back(t_mlx_info *mlx_info);
void	move_obj_forward(t_mlx_info *mlx_info);
void	rotate_ccw(t_mlx_info *mlx_info);
void	rotate_cw(t_mlx_info *mlx_info);

static const t_key_func	g_keycode_table[128] = {
		move_obj_left,
	/*1*/move_obj_back,
	/*2*/move_obj_right,
	/*3*/dummy_func,
	/*4*/dummy_func,
	/*5*/dummy_func,
dummy_func,
dummy_func,
dummy_func,
dummy_func,
	/*10*/dummy_func,
	/*11*/dummy_func,
rotate_ccw,
move_obj_forward,
rotate_cw,
	/*15*/dummy_func,
	/*16*/dummy_func,
	/*17*/dummy_func,
dummy_func,
dummy_func,
	/*20*/dummy_func,
	/*21*/dummy_func,
	/*22*/dummy_func,
	/*23*/dummy_func,
	/*24*/dummy_func,
	/*25*/dummy_func,
	/*26*/dummy_func,
	/*27*/dummy_func,
	/*28*/dummy_func,
	/*29*/dummy_func,
	/*30*/dummy_func,
dummy_func,
dummy_func,
	/*33*/dummy_func,
dummy_func,
	/*35*/dummy_func,
	/*36*/dummy_func,
dummy_func,
dummy_func,
	/*39*/dummy_func,
dummy_func,
	/*41*/dummy_func,
	/*42*/dummy_func,
dummy_func,
dummy_func,
dummy_func,
dummy_func,
dummy_func,
dummy_func,
dummy_func,
	/*50*/dummy_func,
	/*51*/dummy_func,
	/*52*/dummy_func,
	/*53*/exit_program,
dummy_func,
	/*55*/dummy_func,
	/*56*/dummy_func,
	/*57*/dummy_func,
	/*58*/dummy_func,
	/*59*/dummy_func,
	/*60*/dummy_func,
	/*61*/dummy_func,
	/*62*/dummy_func,
	/*63*/dummy_func,
	/*64*/dummy_func,
	/*65*/dummy_func,
	/*66*/dummy_func,
	/*67*/dummy_func,
	/*68*/dummy_func,
	/*69*/dummy_func,
	/*70*/dummy_func,
	/*71*/dummy_func,
	/*72*/dummy_func,
	/*73*/dummy_func,
	/*74*/dummy_func,
	/*75*/dummy_func,
	/*76*/dummy_func,
	/*77*/dummy_func,
	/*78*/dummy_func,
	/*79*/dummy_func,
	/*80*/dummy_func,
	/*81*/dummy_func,
	/*82*/dummy_func,
	/*83*/dummy_func,
	/*84*/dummy_func,
	/*85*/dummy_func,
	/*86*/dummy_func,
	/*87*/dummy_func,
	/*88*/dummy_func,
	/*89*/dummy_func,
	/*90*/dummy_func,
	/*91*/dummy_func,
	/*92*/dummy_func,
	/*93*/dummy_func,
	/*94*/dummy_func,
	/*95*/dummy_func,
	/*96*/dummy_func,
	/*97*/dummy_func,
	/*98*/dummy_func,
	/*99*/dummy_func,
	/*100*/dummy_func,
	/*101*/dummy_func,
	/*102*/dummy_func,
	/*103*/dummy_func,
	/*104*/dummy_func,
	/*105*/dummy_func,
	/*106*/dummy_func,
	/*107*/dummy_func,
	/*108*/dummy_func,
	/*109*/dummy_func,
	/*110*/dummy_func,
	/*111*/dummy_func,
	/*112*/dummy_func,
	/*113*/dummy_func,
	/*114*/dummy_func,
	/*115*/dummy_func,
	/*116*/dummy_func,
	/*117*/dummy_func,
	/*118*/dummy_func,
	/*119*/dummy_func,
	/*120*/dummy_func,
	/*121*/dummy_func,
	/*122*/dummy_func,
	/*123*/dummy_func,
	/*124*/dummy_func,
	/*125*/dummy_func,
	/*126*/dummy_func,
	/*127*/dummy_func
};
#endif
