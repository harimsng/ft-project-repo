/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:24:32 by hseong            #+#    #+#             */
/*   Updated: 2021/10/17 17:44:06 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*expand(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	if (str == (void *)0)
		return ((void *)0);
	if (*to_find == 0 || to_find == (void *)0)
		return (str);
	return (expand(str, to_find));
}

char	*expand(char *str, char *to_find)
{
	char	*ret;
	char	*itr;

	ret = (void *)0;
	while (*str != 0)
	{
		if (*str == *to_find)
		{
			ret = str;
			itr = to_find;
			while (*str == *itr && *str != 0 && *itr != 0)
			{
				++str;
				++itr;
			}
			if (*itr == 0)
				break ;
			str = ret;
			ret = (void *)0;
		}
		++str;
	}
	return (ret);
}
