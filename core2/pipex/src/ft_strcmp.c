/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:33:31 by hseong            #+#    #+#             */
/*   Updated: 2022/03/15 13:34:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		++a;
		++b;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}