#include "libft.h"
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	long long	arr[2];
//	long long	*ptr;

//	ptr = (long long *)malloc(sizeof(long long) * 4);
	ft_print_memory(arr, 16);
	printf("\n");
	ft_memset(arr, 0, 16);
	ft_print_memory(arr, 16);
	printf("\n");
	ft_memset(arr, 17, 9);
	ft_print_memory(arr, 16);
	printf("\n");
	ft_print_memory(arr, 16);
	printf("\n");
	ft_memset(arr, 0, 1);
	ft_print_memory(arr, 16);
	printf("\n");
/*	printf("\n");
	ft_print_memory(ptr, 32);
	printf("\n");
	ft_memset(ptr, 0, 32);
	ft_print_memory(ptr, 32);
	printf("\n");
	ft_memset(ptr, 17, 17);
	ft_print_memory(ptr, 32);
*/
/*
	unsigned int			test = (1 << 31) + 1;
	unsigned long long		test2 = 0x1000000000000001;

	ft_print_memory(&test, 8);
	ft_memset(&test, 0, 1);
	ft_print_memory(&test, 8);
	printf("%d\n\n", test);
	ft_print_memory(&test2, 8);
	ft_memset(&test2, 0, 1);
	ft_print_memory(&test2, 8);
	printf("%lld\n\n", test2);
*/
	return (0);
}
