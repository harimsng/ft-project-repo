/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:31:13 by hseong            #+#    #+#             */
/*   Updated: 2021/10/18 18:30:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		abs(int a);
int		validity_check(int *queens, int col);
void	recur(int *queens, int col, int *retptr);
void	print_queens(int *queens);

int	ft_ten_queens_puzzle(void)
{
	int		queens[10];
	int		idx;
	int		ret;

	ret = 0;
	idx = 0;
	while (idx < 10)
		queens[idx++] = 0;
	recur(queens, 0, &ret);
	return (ret);
}

int	validity_check(int *queens, int col)
{
	int		idx;
	int		jdx;

	idx = 0;
	while (idx < col - 1)
	{
		jdx = idx + 1;
		while (jdx < col)
		{
			if (queens[idx] == queens[jdx])
				return (0);
			else if (abs(queens[idx] - queens[jdx]) == abs(idx - jdx))
				return (0);
			++jdx;
		}
		++idx;
	}
	return (1);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	recur(int *queens, int col, int *retptr)
{
	int		idx;

	if (!validity_check(queens, col))
		return ;
	if (col == 10)
	{
		++(*retptr);
		print_queens(queens);
		return ;
	}
	idx = 0;
	while (idx < 10)
	{
		queens[col] = idx;
		recur(queens, col + 1, retptr);
		++idx;
	}
}

void	print_queens(int *queens)
{
	int		idx;
	char	num;

	idx = 0;
	while (idx < 10)
	{
		num = '0' + queens[idx];
		write(1, &num, 1);
		++idx;
	}
	write(1, "\n", 1);
}
