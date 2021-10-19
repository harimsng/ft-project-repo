/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:10:21 by hseong            #+#    #+#             */
/*   Updated: 2021/10/19 15:50:13 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*zeroinput(char *base_to);

char	*str_encode(int num, char *base_to, int bt_len, int nsign)
{
	int		str_len;
	int		idx;
	char	*ret;

	if (num == 0)
		return (zeroinput(base_to));
	str_len = nsign;
	idx = num;
	while (idx > 0)
	{
		++str_len;
		idx /= bt_len;
	}
	ret = (char *)malloc(sizeof(char) * (str_len + 1));
	if (nsign)
		*ret = '-';
	ret[str_len] = 0;
	idx = str_len - 1;
	while (idx >= nsign)
	{
		ret[idx] = base_to[num % bt_len];
		num /= bt_len;
		--idx;
	}
	return (ret);
}

char	*zeroinput(char *base_to)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char));
	*ret = base_to[0];	
	return (ret);
}
