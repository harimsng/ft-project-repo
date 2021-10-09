/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 01:07:36 by hseong            #+#    #+#             */
/*   Updated: 2021/10/08 01:45:56 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aux(char first, char second, char third);

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0';
	second = '1';
	third = '2';
	aux(first, second, third);
	write(1, "7", 1);
	write(1, "8", 1);
	write(1, "9", 1);
}

void	aux(char first, char second, char third)
{
	while (first < '7')
	{
		if (first < second && second < third)
		{
			write(1, &first, 1);
			write(1, &second, 1);
			write(1, &third, 1);
			write(1, ", ", 2);
		}
		++third;
		if (third > '9')
		{
			++second;
			third = second + 1;
		}
		if (second > '8')
		{
			++first;
			second = first + 1;
			third = second + 1;
		}
	}
}
