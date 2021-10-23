/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 20:15:54 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 20:00:51 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*find_next(int (*thing)(char, char *), char *str, char *charset);
int		find_word(char c, char *charset);
int		find_delim(char c, char *charset);
int		get_arr_len(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	char			**ret;
	char			*temp;
	int				arr_len;
	int				idx;

	arr_len = get_arr_len(str, charset);
	ret = (char **)malloc(sizeof(char *) * (arr_len + 1));
	ret[arr_len] = 0;
	idx = 0;
	while (idx < arr_len)
	{
		temp = find_next(find_word, str, charset);
		str = find_next(find_delim, temp, charset);
		if (ft_atou(temp) == -1)
			continue;
		ret[idx++] = ft_strndup(temp, (unsigned int)(str - temp));
	}
	return (ret);
}

int	get_arr_len(char *str, char *charset)
{
	int				len;

	len = 0;
	while (*str)
	{
		str = find_next(find_word, str, charset);
		if (!*str)
			break ;
		if (ft_atou(str) == -1)
			--len;
		str = find_next(find_delim, str, charset);
		++len;
	}
	return (len);
}

char	*find_next(int (*thing)(char, char *), char *str, char *charset)
{
	while (*str && thing(*str, charset))
		++str;
	return (str);
}

int	find_word(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

int	find_delim(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (0);
		++charset;
	}
	return (1);
}
