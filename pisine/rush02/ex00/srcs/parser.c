/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:23:21 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 22:45:21 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dict.h"
#include "../includes/ft.h"

#define		BUF_LEN		64

char		*get_dict(const char *filename);
t_dict		*alloc_arr(char *dict, int *arr_len);

int	parser(const char *filename, t_dict **arr, int *arr_len)
{
	char		*dict;
	
	dict = get_dict(filename);
	if (!dict)
		return (-1);
	*arr = alloc_arr(dict, arr_len);
	free(dict);
	if (!*arr)
		return (-2);
	return (0);
}
// !dict	> Dict Error (can be Malloc Error)
// !arr		> Malloc Error

char	*get_dict(const char *filename)
{
	char		*dict;
	char		buf[BUF_LEN];
	int			fd;
	int			read_size;
	int			dict_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	dict_size = 0;
	while ((read_size = read(fd, buf, BUF_LEN)) > 0)
		dict_size += read_size;
	if (read_size == -1 || close(fd) == -1)
		return (0);
	dict = (char *)malloc(sizeof(char) * (dict_size + 1));
	if ((fd = open(filename, O_RDONLY)) == -1 || read(fd, dict, dict_size) < 0)
		return (0);
	dict[dict_size] = 0;
	return (dict);
}

// negative keys ignored(no allocation).
// ft_split and ft_strs_to_tab used.
t_dict	*alloc_arr(char *dict, int *arr_len)
{
	char		**dict_split;
	t_dict		*ret;
	*arr_len = 0;
	dict_split = ft_split(dict, "\n");
	if (!dict_split)
		return (0);
	while (dict_split[*arr_len])
		++*arr_len;
	ret = ft_strs_to_tab(*arr_len, dict_split);
	if (!ret)
		return (0);
	return (ret);
}
// !dict_split	> Malloc Error
// !ret 		> Malloc Error
