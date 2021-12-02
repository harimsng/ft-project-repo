/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:36:32 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 19:35:03 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(va_list arg, void *buf)
{
	char	*str;
	
	(void)arg;
	str = buf;
	*str++ = '%';
	*str = 0;
	return (0);
}
