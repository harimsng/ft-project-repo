/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keymap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:26:57 by hseong            #+#    #+#             */
/*   Updated: 2022/04/18 21:44:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_KEYMAP_H
# define FDF_KEYMAP_H

# include "fdf_type.h"
# include "fdf_const.h"

typedef void			(*t_key_func)(t_mlx_info *mlx_info);

void	dummy_func(t_mlx_info *mlx_info);
void	exit_program(t_mlx_info *mlx_info);

void	project_isometric(t_mlx_info *mlx_info);
void	project_perspective(t_mlx_info *mlx_info);
void	automove_map(t_mlx_info *mlx_info);
void	turn_interface(t_mlx_info *mlx_info);
void	turn_diag(t_mlx_info *mlx_info);
void	turn_background(t_mlx_info *mlx_info);
void	turn_wireframe(t_mlx_info *mlx_info);
void	set_default(t_mlx_info *mlx_info);

void	move_obj_left(t_mlx_info *mlx_info);
void	move_obj_right(t_mlx_info *mlx_info);
void	move_obj_forward(t_mlx_info *mlx_info);
void	move_obj_back(t_mlx_info *mlx_info);
void	move_obj_up(t_mlx_info *mlx_info);
void	move_obj_down(t_mlx_info *mlx_info);
void	rotate_ccw(t_mlx_info *mlx_info);
void	rotate_cw(t_mlx_info *mlx_info);
void	rotate_pitch(t_mlx_info *mlx_info);
void	rotate_rpitch(t_mlx_info *mlx_info);
void	rotate_roll(t_mlx_info *mlx_info);
void	rotate_rroll(t_mlx_info *mlx_info);
void	scale_up(t_mlx_info *mlx_info);
void	scale_down(t_mlx_info *mlx_info);
void	height_up(t_mlx_info *mlx_info);
void	height_down(t_mlx_info *mlx_info);

# ifdef SYS_MAC
// mac keycode
static const t_key_func	g_keycode_table[128] = {
	/*0*/move_obj_right,
	/*1*/move_obj_forward,
	/*2*/move_obj_left,
	/*3*/dummy_func,
	/*4*/dummy_func,
	/*5*/dummy_func,
	/*6*/automove_map,
	/*7*/turn_interface,
	/*8*/turn_background,
	/*9*/turn_wireframe,
	/*10*/dummy_func,
	/*11*/dummy_func,
	/*12*/move_obj_down,
	/*13*/move_obj_back,
	/*14*/move_obj_up,
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
	/*31*/scale_down,
	/*32*/scale_up,
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
	/*127*/dummy_func,
};
# else
// x11 keycode
static const t_key_func	g_keycode_table[256] = {
/*0*/dummy_func,
/*1*/dummy_func,
/*2*/dummy_func,
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
/*13*/dummy_func,
/*14*/dummy_func,
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
/*27*/exit_program,
/*28*/dummy_func,
/*29*/dummy_func,
/*30*/dummy_func,
/*31*/dummy_func,
/*32*/set_default,
/*33*/dummy_func,
/*34*/dummy_func,
/*35*/dummy_func,
/*36*/dummy_func,
/*37*/dummy_func,
/*38*/dummy_func,
/*39*/dummy_func,
/*40*/dummy_func,
/*41*/dummy_func,
/*42*/dummy_func,
/*43*/dummy_func,
/*44*/height_up,
/*45*/dummy_func,
/*46*/height_down,
/*47*/dummy_func,
/*48*/dummy_func,
/*49*/project_isometric,
/*50*/project_perspective,
/*51*/dummy_func,
/*52*/dummy_func,
/*53*/dummy_func,
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
/*97*/move_obj_left,
/*98*/dummy_func,
/*99*/turn_background,
/*100*/move_obj_right,
/*101*/move_obj_down,
/*102*/dummy_func,
/*103*/dummy_func,
/*104*/dummy_func,
/*105*/rotate_rpitch,
/*106*/rotate_cw,
/*107*/rotate_pitch,
/*108*/rotate_ccw,
/*109*/dummy_func,
/*110*/dummy_func,
/*111*/scale_up,
/*112*/dummy_func,
/*113*/move_obj_up,
/*114*/dummy_func,
/*115*/move_obj_back,
/*116*/dummy_func,
/*117*/scale_down,
/*118*/turn_wireframe,
/*119*/move_obj_forward,
/*120*/turn_interface,
/*121*/dummy_func,
/*122*/automove_map,
/*123*/dummy_func,
/*124*/dummy_func,
/*125*/dummy_func,
/*126*/dummy_func,
/*127*/dummy_func,
/*128*/dummy_func,
/*129*/dummy_func,
/*130*/dummy_func,
/*131*/dummy_func,
/*132*/dummy_func,
/*133*/dummy_func,
/*134*/dummy_func,
/*135*/dummy_func,
/*136*/dummy_func,
/*137*/dummy_func,
/*138*/dummy_func,
/*139*/dummy_func,
/*140*/dummy_func,
/*141*/dummy_func,
/*142*/dummy_func,
/*143*/dummy_func,
/*144*/dummy_func,
/*145*/dummy_func,
/*146*/dummy_func,
/*147*/dummy_func,
/*148*/dummy_func,
/*149*/dummy_func,
/*150*/dummy_func,
/*151*/dummy_func,
/*152*/dummy_func,
/*153*/dummy_func,
/*154*/dummy_func,
/*155*/dummy_func,
/*156*/dummy_func,
/*157*/dummy_func,
/*158*/dummy_func,
/*159*/dummy_func,
/*160*/dummy_func,
/*161*/dummy_func,
/*162*/dummy_func,
/*163*/dummy_func,
/*164*/dummy_func,
/*165*/dummy_func,
/*166*/dummy_func,
/*167*/dummy_func,
/*168*/dummy_func,
/*169*/dummy_func,
/*170*/dummy_func,
/*171*/dummy_func,
/*172*/dummy_func,
/*173*/dummy_func,
/*174*/dummy_func,
/*175*/dummy_func,
/*176*/dummy_func,
/*177*/dummy_func,
/*178*/dummy_func,
/*179*/dummy_func,
/*180*/dummy_func,
/*181*/dummy_func,
/*182*/dummy_func,
/*183*/dummy_func,
/*184*/dummy_func,
/*185*/dummy_func,
/*186*/dummy_func,
/*187*/dummy_func,
/*188*/dummy_func,
/*189*/dummy_func,
/*190*/dummy_func,
/*191*/dummy_func,
/*192*/dummy_func,
/*193*/dummy_func,
/*194*/dummy_func,
/*195*/dummy_func,
/*196*/dummy_func,
/*197*/dummy_func,
/*198*/dummy_func,
/*199*/dummy_func,
/*200*/dummy_func,
/*201*/dummy_func,
/*202*/dummy_func,
/*203*/dummy_func,
/*204*/dummy_func,
/*205*/dummy_func,
/*206*/dummy_func,
/*207*/dummy_func,
/*208*/dummy_func,
/*209*/dummy_func,
/*210*/dummy_func,
/*211*/dummy_func,
/*212*/dummy_func,
/*213*/dummy_func,
/*214*/dummy_func,
/*215*/dummy_func,
/*216*/dummy_func,
/*217*/dummy_func,
/*218*/dummy_func,
/*219*/dummy_func,
/*220*/dummy_func,
/*221*/dummy_func,
/*222*/dummy_func,
/*223*/dummy_func,
/*224*/dummy_func,
/*225*/dummy_func,
/*226*/dummy_func,
/*227*/dummy_func,
/*228*/dummy_func,
/*229*/dummy_func,
/*230*/dummy_func,
/*231*/dummy_func,
/*232*/dummy_func,
/*233*/dummy_func,
/*234*/dummy_func,
/*235*/dummy_func,
/*236*/dummy_func,
/*237*/dummy_func,
/*238*/dummy_func,
/*239*/dummy_func,
/*240*/dummy_func,
/*241*/dummy_func,
/*242*/dummy_func,
/*243*/dummy_func,
/*244*/dummy_func,
/*245*/dummy_func,
/*246*/dummy_func,
/*247*/dummy_func,
/*248*/dummy_func,
/*249*/dummy_func,
/*250*/dummy_func,
/*251*/dummy_func,
/*252*/dummy_func,
/*253*/dummy_func,
/*254*/dummy_func,
/*255*/dummy_func,
};
# endif
#endif

