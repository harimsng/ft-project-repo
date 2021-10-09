/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:42:10 by hseong            #+#    #+#             */
/*   Updated: 2021/10/08 01:05:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);

int	main(void)
{
	ft_print_reverse_alphabet();
	write(1, "\n", 1);
	ft_print_numbers();
	write(1, "\n", 1);
	ft_is_negative(2);
	write(1, "\n", 1);
	ft_is_negative(-2);
	write(1, "\n", 1);
	return (0);
}	
