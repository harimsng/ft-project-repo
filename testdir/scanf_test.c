/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:10:16 by hseong            #+#    #+#             */
/*   Updated: 2022/04/21 16:20:54 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	FILE	*fp = fopen("stest", "r");
	float	arr[2];
     
	printf("first return : %d\n", fscanf(fp, "%f", arr));
	printf("first value : %f\n", arr[0]);
	printf("second return : %d\n", fscanf(fp, "\n%f\t", arr + 1));
	printf("second value : %f\n", arr[1]);
	return (0);
}
