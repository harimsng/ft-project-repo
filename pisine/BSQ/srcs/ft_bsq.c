/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:43:42 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 22:08:26 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

# include <stdio.h>

t_map	*ft_map(char *filename);

int	main(int argc, char **argv)
{
	t_map			*data;
	unsigned int	idx;
	unsigned int	jdx;

	if (argc < 2)
		return (0);
	printf("main1\n");
	data = ft_map(argv[1]);
	printf("main2\n");
	printf("%u\n", data->lines);
	printf("%u\n", data->width);
	printf("%c\n", data->empty);
	printf("%c\n", data->obs);
	printf("%c\n", data->full);
	idx = 0;
	while (idx < data->lines)
	{
		jdx = 0;
		printf("%llu\n", data->pos[idx][0]);
		printf("%llu\n", data->pos[idx][1]);
		while (jdx < data->width)
		{
			printf("%d ", 0 != ((1 << jdx) & ((data->pos)[idx][jdx >> 6])));
			++jdx;
		}
		printf("\n");
		++idx;
	}
/*
	if (argc == 1)
		ft_map(0);
	else
	{
		while (*argv)
		{

		}

*/	
	return (0);
}
