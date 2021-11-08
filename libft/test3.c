#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		arr[2] = {0, };
	int		arr2[2] = {0, };
	void	*ptr;
	void	*ptr2;

/*	ptr = arr;
	printf("|%s|\n", (char *)memset(ptr, 65, 7));
	ptr2 = arr2;
	printf("|%s|\n", (char *)ft_memset(ptr2, 65, 7));

	bzero(ptr, 8);
	printf("|%s|\n", (char *)ptr);
	bzero(ptr2, 8);
	printf("|%s|\n", (char *)ptr2);
*/
	ptr = "12345678";
	memcpy(arr, ptr, 7);
	printf("|%s|\n", (char *)arr);
	ptr2 = "12345678";
	memcpy(arr2, ptr2, 7);
	printf("|%s|\n", (char *)arr2);
	return (0);
}
