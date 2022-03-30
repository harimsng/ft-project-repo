/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_order.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:50:34 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 17:48:57 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_RENDER_ORDER_H
# define FDF_RENDER_ORDER_H

# include "fdf_type.h"

typedef void	(*t_draw)(t_img_elem *, t_vertex *, t_vertex *);
typedef void	(*t_render)(t_img_elem *, t_map_info *, t_draw);

// rendering with diagonal line
// a function for each quadrant, diagonal render
void	render_d0(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_d1(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_d2(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_d3(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_d4(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_d5(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_d6(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_d7(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);

// rendering without diagonal line, normal render
void	render_n0(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_n1(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_n2(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_n3(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_n4(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_n5(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_n6(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
void	render_n7(t_img_elem *img_elem, t_map_info *map_info, t_draw draw);
#endif
