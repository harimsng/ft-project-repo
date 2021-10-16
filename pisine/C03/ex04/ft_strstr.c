/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:24:32 by hseong            #+#    #+#             */
/*   Updated: 2021/10/16 23:15:25 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ret;
	char	*itr;

	if (str == 0)
		return (0);
	if (*to_find == 0 || to_find == 0)
		return (str);
	ret = 0;
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
			ret = 0;
			continue ;
		}
		++str;
	}
	return (ret);
}
