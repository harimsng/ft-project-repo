/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:32:59 by hseong            #+#    #+#             */
/*   Updated: 2022/06/02 17:28:29 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <time.h>

#define ALLOC_SIZE (UINT_MAX)

int	main(void)
{
	void	*b = (void *)1;
	size_t	allocated_mem = 0;
	unsigned int		idx = 0;

	srand(clock());
	while (b)
	{
		b = malloc(ALLOC_SIZE);
		allocated_mem += ALLOC_SIZE;
		if (idx % 10== 0)
		{
			srand(clock());
			printf("allocated memory: %10zd bytes|%10zd KB|%10zd MB|%10zd GB\n",
				allocated_mem, allocated_mem / 1000, allocated_mem / 1000000, allocated_mem / 1000000000);
		}
//		memset(b, rand(), ALLOC_SIZE);
		++idx;
		sleep(1);
	}
	printf("allocated memory: %10zd bytes|%10zd KB|%10zd MB|%10zd GB\n",
		allocated_mem, allocated_mem / 1000, allocated_mem / 1000000, allocated_mem / 1000000000);
	perror(NULL);
	return (0);
}
