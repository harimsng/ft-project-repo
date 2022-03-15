/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:02:11 by hseong            #+#    #+#             */
/*   Updated: 2021/11/17 15:07:37 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// different with linux
int	ft_toupper(int c)
{
	return (c - 32 * (c > 96 && c < 123));
}