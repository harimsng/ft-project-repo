/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:16:11 by hseong            #+#    #+#             */
/*   Updated: 2022/03/23 18:20:45 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strchr(const char *set, int c);
static char		*ft_strndup(const char *src, size_t len);
static size_t	get_count(const char *str, char *delim);
static char		**alloc_words(const char *str, size_t count, char *delim);
static void		dealloc_words(char **str_arr, size_t size);

char	**ft_split(const char *str, char *delim)
{
	size_t	count;

	count = get_count(str, delim);
	return (alloc_words(str, count, delim));
}

size_t	get_count(const char *str, char *delim)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (ft_strchr(delim, *str) == NULL
				&& (ft_strchr(delim, str[1]) != NULL || str[1] == 0))
			++count;
		++str;
	}
	return (count);
}

char	**alloc_words(const char *str, size_t count, char *delim)
{
	char	**str_arr;
	size_t	str_idx;
	size_t	idx;

	str_arr = malloc(sizeof(char *) * (count + 1));
	if (str_arr == NULL)
		return (NULL);
	str_arr[count] = NULL;
	str_idx = 0;
	while (str_idx < count)
	{
		idx = 0;
		while (ft_strchr(delim, str[idx]) != NULL)
			++str;
		while (str[idx] && ft_strchr(delim, str[idx]) == NULL)
			++idx;
		str_arr[str_idx] = ft_strndup(str, idx);
		if (str_arr[str_idx] == NULL)
			break ;
		str += idx;
		++str_idx;
	}
	if (str_idx != count)
		dealloc_words(str_arr, str_idx);
	return (str_arr);
}

void	dealloc_words(char **str_arr, size_t size)
{
	size_t		idx;

	idx = 0;
	while (idx < size)
	{
		free(str_arr[idx]);
		++idx;
	}
	free(str_arr);
}

char	*ft_strndup(const char *src, size_t len)
{
	char	*dst;
	size_t	idx;

	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	dst[len] = 0;
	idx = 0;
	while (idx < len && src[idx])
	{
		dst[idx] = src[idx];
		++idx;
	}
	while (idx < len)
	{
		dst[idx] = 0;
		++idx;
	}
	return (dst);
}
