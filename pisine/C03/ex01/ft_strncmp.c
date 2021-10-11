/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:52:58 by hseong            #+#    #+#             */
/*   Updated: 2021/10/11 21:55:16 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && *s1 == *s2 && *s1 != 0 && *s2 != 0)
	{
		++s1;
		++s2;
		++idx;
	}
	if (idx == n)
	{
		--s1;
		--s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
