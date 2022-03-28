/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:42:44 by hseong            #+#    #+#             */
/*   Updated: 2022/03/28 20:38:33 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_keymap.h"

typedef void	(*keycode_func)(t_mlx_info *mlx_info);

static void	dummy_func(t_mlx_info *mlx_info);
static void	exit_program(t_mlx_info *mlx_info);

static const keycode_func	g_keycode_table[128] = {
/*0*/move_obj_left,
/*1*/move_obj_down,
/*2*/move_obj_right,
/*3*/dummy_func,
/*4*/dummy_func,
/*5*/dummy_func,
/*6*/dummy_func,
/*7*/dummy_func,
/*8*/dummy_func,
/*9*/dummy_func,
/*10*/dummy_func,
/*11*/dummy_func,
/*12*/dummy_func,
/*13*/move_obj_up,
/*14*/scale_up,
/*15*/dummy_func,
/*16*/dummy_func,
/*17*/dummy_func,
/*18*/dummy_func,
/*19*/dummy_func,
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
/*31*/dummy_func,
/*32*/scale_down,
/*33*/dummy_func,
/*34*/rotate_roll,
/*35*/dummy_func,
/*36*/dummy_func,
/*37*/rotate_ccw,
/*38*/rotate_cw,
/*39*/dummy_func,
/*40*/rotate_rroll,
/*41*/dummy_func,
/*42*/dummy_func,
/*43*/dummy_func,
/*44*/dummy_func,
/*45*/dummy_func,
/*46*/dummy_func,
/*47*/dummy_func,
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
};

int	key_hook(int keycode, void *param)
{
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
