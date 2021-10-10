/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:03:17 by hseong            #+#    #+#             */
/*   Updated: 2021/10/10 00:40:27 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize(char *arr);
void	num_print(char *arr, int n);
void	check_overlap(char *arr, int n);
void	last_print(int n);

void	ft_print_combn(int n)
{
	char	nums[9];

	initialize(nums);
	while (nums[0] < '9' - n + 1)
	{
		num_print(nums, n);
		++nums[n - 1];
		check_overlap(nums, n);
	}
	last_print(n);
}

void	initialize(char *arr)
{
	int		idx;

	idx = 0;
	while (idx < 9)
	{
		arr[idx] = '0' + idx;
		idx++;
	}
}

void	num_print(char *arr, int n)
{
	int		idx;

	idx = 0;
	while (idx < n)
	{
		write(1, arr + idx, 1);
		++idx;
	}
	write(1, ",", 1);
	write(1, " ", 1);
}

void	check_overlap(char *arr, int n)
{
	int		idx;
	int		idx2;

	idx = n - 1;
	while (idx > 0)
	{
		if (arr[idx] > '9' + idx - n + 1)
		{
			++arr[idx - 1];
			idx2 = idx;
			while (idx2 < n)
			{
				arr[idx2] = arr[idx2 - 1] + 1;
				++idx2;
			}
		}
		--idx;
	}
}

void	last_print(int n)
{
	char	firstnum;
	int		idx;

	firstnum = '9' - n + 1;
	idx = 0;
	while (idx < n)
	{
		write(1, &firstnum, 1);
		++firstnum;
		++idx;
	}
}
