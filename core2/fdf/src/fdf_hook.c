/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:42:44 by hseong            #+#    #+#             */
/*   Updated: 2022/04/01 20:08:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_keymap.h"

typedef void			(*t_key_func)(t_mlx_info *mlx_info);

static void	dummy_func(t_mlx_info *mlx_info);
static void	exit_program(t_mlx_info *mlx_info);

static const t_key_func	g_keycode_table[128] = {
/*0*/move_obj_left,
/*1*/move_obj_back,
/*2*/move_obj_right,
/*3*/dummy_func,
/*4*/dummy_func,
/*5*/dummy_func,
/*6*/automove_map,
/*7*/turn_interface,
/*8*/dummy_func,
/*9*/dummy_func,
/*10*/dummy_func,
/*11*/dummy_func,
/*12*/scale_up,
/*13*/move_obj_forward,
/*14*/scale_down,
/*15*/dummy_func,
/*16*/dummy_func,
/*17*/dummy_func,
/*18*/project_isometric,
/*19*/project_perspective,
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
/*31*/move_obj_up,
/*32*/move_obj_down,
/*33*/dummy_func,
/*34*/rotate_rpitch,
/*35*/dummy_func,
/*36*/dummy_func,
/*37*/rotate_ccw,
/*38*/rotate_cw,
/*39*/dummy_func,
/*40*/rotate_pitch,
/*41*/dummy_func,
/*42*/dummy_func,
/*43 ,*/height_down,
/*44*/dummy_func,
/*45*/dummy_func,
/*46*/dummy_func,
/*47 .*/height_up,
/*48*/dummy_func,
/*49*/set_default,
/*50*/dummy_func,
/*51*/dummy_func,
/*52*/dummy_func,
/*53*/exit_program,
/*54*/dummy_func,
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
};

int	key_hook(int keycode, void *param)
{
	if (keycode > 53)
		return (0);
	g_keycode_table[keycode](param);
	return (0);
}

void	dummy_func(t_mlx_info *mlx_info)
{
	(void)mlx_info;
}

static void	exit_program(t_mlx_info *mlx_info)
{
	(void)mlx_info;
	exit(0);
}
