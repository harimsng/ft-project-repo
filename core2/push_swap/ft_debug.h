/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:13:31 by hseong            #+#    #+#             */
/*   Updated: 2022/01/27 20:47:28 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

#include <stdio.h>
#define DEBUG(M, ...) printf("%s:%s:%d DEBUG: " M "\n",\
		__FILE__, __func__, __LINE__, ##__VA_ARGS__);

#endif
