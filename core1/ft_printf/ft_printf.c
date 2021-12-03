/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:40:01 by hseong            #+#    #+#             */
/*   Updated: 2021/12/03 21:37:53 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// format: %[flags][width][.precision][length]specifier
// [flags] = '+', ' ', "0x" or "0X" 
// output: [padding][flags][integer precision][number][.float precision][-padding]
// string: [padding][string precision][padding]

static int			format_io(const char **format, va_list arg);
static int			write_process(t_format_info *info, char *buf);
static void			read_options(const char **format, t_format_info *info);

static const char	*pre_cha = " +0x0X";

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
			ret += format_io(&format, arg);
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

static int	format_io(const char **format, va_list arg)
{
	t_format_info	info;
	char			buf[NUMERIC_BUF_SIZE];
	void			*buf_ptr;

	buf_ptr = (void *)buf;
	info = (t_format_info){0, 0, 0, 0};
	read_options(format, &info);
	if (info.conv < 0)
		return (info.min_field);
	if (info.conv == 1)
		buf_ptr = &buf_ptr;
	if (g_conv_func[info.conv](arg, buf_ptr) < 0)
		return (INT_MIN);
	info.bit_flag &= MAX_BIT - 8 * (*(char *)buf_ptr == '-');
	return (write_process(&info, buf_ptr));
}

static int	write_process(t_format_info *info, char *buf)
{
	int			len;
	int			ret;

	len = ft_strlen(buf) + !!(info->bit_flag & 28) + !!(info->bit_flag & 16);
	ret = 0;
	if (!(info->bit_flag & 1) && !(info->bit_flag & 2))
		ret += opt_padding(*info, len);
	if (info->bit_flag & 28 || info->conv == 2)
		write(1, pre_cha + (info->bit_flag & 8)
			+ 2 * (info->conv == 6 || info->conv == 2) + 4 * (info->conv == 7),
			1 + (info->conv == 6 || info->conv == 7 || info->conv == 2));
	else if (info->conv > 1 && buf[0] == '-')
		write(1, buf, 1);
	ret += opt_precision(*info, buf, len);
	if (info->bit_flag & 1)
		ret += opt_padding(*info, len);
	return (ret);
}

static void	read_options(const char **format, t_format_info *info)
{
	char	*ptr;

	ptr = ft_strchr(g_flag_group, **format);
	while (ptr)
	{
		info->bit_flag |= 1 << (int)(ptr - (char *)g_flag_group);
		++*format;
		ptr = ft_strchr(g_flag_group, **format);
	}
	if (**format >= '0' && **format <= '9')
		info->min_field = ft_atoi((*format)++);
	if (**format == '.' && *(*format + 1) >= '0' && *(*format + 1) <= '9')
		info->precision = ft_atoi(++*format);
	while (**format >= 0 && **format <= '9')
		++*format;
	ptr = ft_strchr(g_conv_group, **format);
	info->conv = -1 * (!ptr) + !!ptr * (ptr - (char *)g_conv_group);
	info->bit_flag &= (MAX_BIT ^ (2 * (info->bit_flag & 1 || info->precision
		|| info->conv == 1 || info->conv == 0)));
	info->bit_flag &= (MAX_BIT ^ (4 * (info->bit_flag & 8 || info->conv == 6
		|| info->conv == 7 || info->conv == 1 || info->conv == 0)));
	info->bit_flag &= (MAX_BIT ^ (8 * (info->conv == 8 || info->conv == 7
		|| info->conv == 6)));
	info->bit_flag &= (MAX_BIT ^ (16 * (info->conv != 6 && info->conv != 7)));
}
