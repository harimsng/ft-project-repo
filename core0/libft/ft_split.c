/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:12:35 by hseong            #+#    #+#             */
/*   Updated: 2021/11/10 19:54:33 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fill_strarr(char *s, char c, size_t size);
static void	*fail_free(char **strarr, size_t size);

char	**ft_split(char const *s, char c)
{
	size_t		idx;
	size_t		size;

	idx = 0;
	size = 0;
	while (s[idx])
	{
		size += (s[idx] != c && (s[idx + 1] == c || s[idx + 1] == 0));
		++idx;
	}
	return (fill_strarr((char *)s, c, size));
}

static char	**fill_strarr(char *s, char c, size_t size)
{
	char		**strarr;
	size_t		idx;
	size_t		jdx;

	strarr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strarr)
		return (NULL);
	strarr[size] = NULL;
	idx = 0;
	while (idx < size)
	{
		while (*s == c)
			++s;
		jdx = 0;
		while (s[jdx] && s[jdx] != c)
			++jdx;
		s[jdx] = 0;
		strarr[idx] = ft_strdup(s);
		if (!strarr[idx])
			return (fail_free(strarr, idx));
		s += jdx + 1;
		++idx;
	}
	return (strarr);
}

static void	*fail_free(char **strarr, size_t size)
{
	size_t		idx;

	idx = 0;
	while (idx < size)
		free(strarr[idx++]);
	free(strarr);
	return (NULL);
}
