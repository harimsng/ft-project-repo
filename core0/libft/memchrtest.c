#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	arr[1024];

	for (int i = 0; i < 1024; ++i)
		arr[i] = i - 512;
	for (int i = -512; i < 512; ++i)
	{
		printf("%p\n", ft_memchr(arr, i, 1024));
		printf("%p\n\n", memchr(arr, i, 1024));
	}
	return (0);	
}
