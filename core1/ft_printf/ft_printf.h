/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:33:23 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 21:09:13 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define MAX_CONV 9
# define MAX_FLAG 7
# define MAX_BIT 1024
# define NUMERIC_BUF_SIZE 32

typedef int 			(*t_conv)(va_list, void *);
typedef unsigned char	bool;

typedef struct s_format_info
{
	int		bit_flag;
	int		min_field;
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
int						print_percent(va_list arg, void *buf);

//	flags
//						padding option
void					opt_negative_field(void);
void					opt_zero_padding(void);
//						preceding character
void					opt_blank(void);
void					opt_plus_sign(void);
//						alternative form(preceding characters)
void					opt_alt_form(void);

//	width, precision
//						padding width
void					opt_min_field(void);
//						precision
void					opt_precision(void);

/*
 * flag collision
 * latters are ignored or resulting UB.
 * '-'				<> '0'
 * '.'				<> '0' (with 'd', 'i', 'u', 'x', 'X', ...)
 * '+'				<> ' '
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
	print_percent
};

static const char		g_conv_group[MAX_CONV] =
{
	99, 115, 112, 105, 100, 117, 120, 88, 37
};
//  'c', 's', 'p', 'i', 'd', 'u', 'x', 'X', '%'

static const char		g_flag_group[MAX_FLAG] = 
{
	'-', '0', ' ', '+', '#'
};
//	'-', '0', ' ', '+', '#' ('.', digit string)
//	'.' and digit string for precision and minimum field width aren't necessary here.
//	there're processed separately.

static const char		*hex_tab = "0123456789abcdef0123456789ABCDEF";
static const char		*pre_hex = "0x0X";

#endif
