/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunchoi <seunchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:10:42 by seunchoi          #+#    #+#             */
/*   Updated: 2021/10/10 18:10:46 by seunchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	up_down_excreta(int x, char left, char center, char right);
void	side_excreta(int x, int y, char side);

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	up_down_excreta(x, 'A', 'B', 'C');
	side_excreta(x, y, 'B');
	if (y > 1)
		up_down_excreta(x, 'C', 'B', 'A');
}

void	up_down_excreta(int x, char left, char center, char right)
{
	ft_putchar(left);
	if (x > 1)
	{
		if (x > 2)
		{
			while (x > 2)
			{
				ft_putchar(center);
				--x;
			}
		}
		ft_putchar(right);
	}
	ft_putchar('\n');
}

void	side_excreta(int x, int y, char side)
{
	int		i;

	while (y > 2)
	{
		i = x;
		ft_putchar(side);
		while (i > 2)
		{
			ft_putchar(' ');
			--i;
		}
		if (i == 2)
			ft_putchar(side);
		ft_putchar('\n');
		--y;
	}	
}
