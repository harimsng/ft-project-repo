/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:33:23 by hseong            #+#    #+#             */
/*   Updated: 2022/01/18 13:18:42 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define MAX_CONV 9
# define MAX_FLAG 9
# define MAX_BIT 1023
# define NUMERIC_BUF_SIZE 32

typedef int				(*t_conv)(va_list, void *);

typedef struct s_format_info
{
	int		bit_flag;
	int		bit_len;
	int		min_width;
	int		precision;
	int		conv;
}						t_format_info;

int						ft_printf(const char *format, ...);

//	conversion group
int						print_char(va_list arg, void *buf);
int						print_string(va_list arg, void *buf);
int						print_pointer(va_list arg, void *buf);
int						print_integer(va_list arg, void *buf);
//int					print_decimal(va_list arg, void *buf);
//						print_decimal == print_integer
int						print_unsigned(va_list arg, void *buf);
int						print_lowhex(va_list arg, void *buf);
int						print_uphex(va_list arg, void *buf);

int						opt_padding(t_format_info *info, int len);
int						opt_precision(t_format_info *info, char *buf, int len);
//	precision for string is its maximum length.
//	precision for integer is minimum number of digits.

/*
 * flag collision
 * latters are ignored or result UB(warning occurs).
 * '-'				<> '0'
 * '.'				<> '0' (with 'd', 'i', 'u', 'x', 'X', ...)
 * '+'				<> ' '
 * negative number	<> '+'
 * 'x', 'u'			<> '+', ' '
 * 's'				<> '0', '+', ' ', '#'
 * 'c', 'p'			<> '0', '+', ' ', '#', '.'
 * 'd', 'i', 'u', 'c', 's', 'p'	<> '#'
 */

static const t_conv		g_conv_func[MAX_CONV] =
{
	print_char,
	print_string,
	print_pointer,
	print_integer,
	print_integer,
	print_unsigned,
	print_lowhex,
	print_uphex,
};

static const char		g_conv_group[MAX_CONV] =
{
	99, 115, 112, 105, 100, 117, 120, 88
};
//  'c', 's', 'p', 'i', 'd', 'u', 'x', 'X'

static const char		g_flag_group[MAX_FLAG] =
{
	'-', '0', ' ', '+', '#', '-'
};
// 	1	 2	  4	   8	16	 32
// 6th element: negative sign.

#endif
