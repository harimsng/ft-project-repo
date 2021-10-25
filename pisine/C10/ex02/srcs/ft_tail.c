/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:24:20 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 22:56:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

// option requires an argument	ex) $> tail -c
// illegal offset				ex) $> tail -c a
// standard input				ex) $> tail -c 5
// multiple input				ex) $> tail -c 3 test test2
// 									==> test <==
// 									...
//
// 									==> test2 <==
// No such file or directory	ex) $> tail -c 5 nonexist

int	main(int argc, char **argv)
{
	if (srgc < 3)
		return (0);

	return (0);
}
