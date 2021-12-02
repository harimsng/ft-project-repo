/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:40:01 by hseong            #+#    #+#             */
/*   Updated: 2021/12/02 21:19:33 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %[flags][width][.precision][length]specifier
// cplusplus.com/reference/cstdio/printf/

static int	output_proc(const char **format, va_list arg);
static void	conv_proc(const char **format, t_format_info *info);

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			ret;

	ret = 0;
	va_start(arg, format);
	while (*format && ret >= 0)
	{
		if (*format == '%')
		{
			++format;
			ret += output_proc(&format, arg);
			if (ret < 0)
				return (-1);
		}
		else
			ret += write(1, format, 1);
		++format;
	}
	va_end(arg);
	return (ret);
}

static int	output_proc(const char **format, va_list arg)
{
	t_format_info	info;
	char			buf[NUMERIC_BUF_SIZE];
	int				len;
	int				ret;

	info = (t_format_info){0, 0, 0, 0};
	conv_proc(format, &info);
	if (info.conv < 0)
		return (info.min_field);
	if (g_conv_func[info.conv](arg, buf) < 0)
		return (INT_MIN);
	len = ft_strlen(buf);
	if (info.bit_flag & 4)
		len += write(1, " ", 1);
	else if (info.bit_flag & 8 && buf[0] != '-')
		len += write(1, "+", 1);
	else if (info.bit_flag & 16)
		len += write(1, pre_hex + 2 * (info.conv == 7), 2);
	buf[info.precision] = 0;
	if (info.min_field - len > 0)

	
}

static void	conv_proc(const char **format, t_format_info *info)
{
	int				idx;

	idx = (int)(ft_strchr(g_flag_group, **format) - (char *)g_flag_group);
	while (idx)
	{
		info->bit_flag |= 1 << idx;
		++*format;
		idx = (int)(ft_strchr(g_flag_group, **format) - (char *)g_flag_group);
	}
	if (**format >= '0' && **format <= '9')
		info->min_field = ft_atoi(*format);
	if (**format == '.' && **format >= '0' && *(*format + 1) <= '9')
		info->precision = ft_atoi(*format);
	idx = (int)(ft_strchr(g_conv_group, **format) - (char *)g_conv_group);
	info->conv = -1 * (!idx) + idx;
	info->bit_flag &= (MAX_BIT ^ (2 * (info->bit_flag & 1 || info->precision
		|| info->conv == 1 || info->conv == 0)));
	info->bit_flag &= (MAX_BIT ^ (4 * (info->bit_flag & 8 || info->conv == 6
		|| info->conv == 7 || info->conv == 1 || info->conv == 0)));
	info->bit_flag &= (MAX_BIT ^ (8 * (info->conv == 8 || info->conv == 7
		|| info->conv == 6)));
	info->bit_flag &= (MAX_BIT ^ (16 * (info->conv != 6 && info->conv != 7)));
}
