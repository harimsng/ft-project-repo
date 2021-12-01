/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:33:23 by hseong            #+#    #+#             */
/*   Updated: 2021/12/01 16:45:30 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define MAX_FORMAT 9

typedef int 			(*t_format)(va_list);

int						print_char(va_list arg);
int						print_string(va_list arg);
int						print_pointer(va_list arg);
int						print_integer(va_list arg);
//int					print_decimal(va_list arg);
int						print_unsigned(va_list arg);
int						print_lowhex(va_list arg);
int						print_uphex(va_list arg);
int						print_percent(va_list arg);

// print_decimal == print_integer
static const t_format	g_format_func[MAX_FORMAT] =
{
	print_char,
	print_string,
	print_pointer,
	print_integer,
	print_integer,
	print_unsigned,
	print_lowhex,
	print_uphex,
	print_percent
};

static const char		g_format_tab[MAX_FORMAT] =
{
	99, 115, 112, 105, 100, 117, 120, 88, 37
};
//  'c', 's', 'p', 'i', 'd', 'u', 'x', 'X', '%'

static const char		*hex_tab = "0123456789abcdef0123456789ABCDEF";

int						ft_printf(const char *format, ...);

#endif
