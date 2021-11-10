#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	int		arr[2] = {0, };
	int		arr2[2] = {0, };
	void	*ptr;
	void	*ptr2;

	ptr = arr;
	printf("|%s|\n", (char *)memset(ptr, 214, 7));
	ft_print_memory(ptr, 8);
	ptr2 = arr2;
	printf("\n|%s|\n", (char *)ft_memset(ptr2, 214, 7));
	ft_print_memory(ptr2, 8);
/*
	bzero(ptr, 8);
	printf("|%s|\n", (char *)ptr);
	bzero(ptr2, 8);
	printf("|%s|\n", (char *)ptr2);

	ptr = "12345678";
	memcpy(arr, ptr, 7);
	printf("|%s|\n", (char *)arr);
	ptr2 = "12345678";
	memcpy(arr2, ptr2, 7);
	printf("|%s|\n", (char *)arr2);
*/
	return (0);
}
