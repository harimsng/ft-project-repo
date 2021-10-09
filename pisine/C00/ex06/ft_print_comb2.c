/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:45:35 by hseong            #+#    #+#             */
/*   Updated: 2021/10/09 14:59:19 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	loop(char *left, char *right);
void	my_print(char *left, char *right);
void	last_part(void);

void	ft_print_comb2(void)
{
	char	left[2];
	char	right[2];

	left[0] = '0';
	left[1] = '0';
	right[0] = '0';
	right[1] = '1';
	loop(left, right);
	write(1, "9", 1);
}

void	loop(char *left, char *right)
{
	while (left[0] != '9' && left[1] != '8')
	{
		if (left[0] != right[0] || left[1] != right[1])
			my_print(left, right);
		++right[1];
		if (right[1] > '9')
		{
			++right[0];
			right[1] = '0';
		}
		if (right[0] > '9')
		{
			++left[1];
			right[0] = left[0];
			right[1] = left[1] + 1;
		}
		if (left[1] > '9')
		{
			++left[0];
			left[1] = '0';
			right[0] = left[0];
			right[1] = left[1] + 1;
		}
	}
}

void	my_print(char *left, char *right)
{
	write(1, left, 1);
	write(1, left + 1, 1);
	write(1, " ", 1);
	write(1, right, 1);
	write(1, right + 1, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	last_part(void)
{
	write(1, "9", 1);
	write(1, "8", 1);
	write(1, " ", 1);
	write(1, "9", 1);
	write(1, "9", 1);
}
