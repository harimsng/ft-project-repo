/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:05:09 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 03:10:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef unsigned char	t_uc;

typedef struct s_map
{
	int					lines;
	int					width;
	char				empty;
	char				obs;
	char				full;
	t_uc				*map;
	int					x;
	int					y;
	int					len;
}	t_map;

#endif
