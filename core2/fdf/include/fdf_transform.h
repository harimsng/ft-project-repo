/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:48:13 by hseong            #+#    #+#             */
/*   Updated: 2022/03/30 19:50:50 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_H
# define FDF_TRANSFORM_H

void	isometric_proj(t_map_info *map_info, t_vertex *to, t_vertex *from);
void	perspective_proj(t_map_info *map_info, t_vertex *to, t_vertex *from);

#endif
