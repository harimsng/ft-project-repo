#include <stdio.h>
#include <string.h>

void	*get_null(void);

int	main(void)
{
	char	arr1[10];
	char	arr2[10];

//	printf("%p\n", memcpy(get_null(), get_null(), 1));
//	printf("%p\t%p\n", arr1, arr2);
//	printf("%p\n", memmove(arr1, arr2, 0));
	printf("%p\n", memchr(arr1, 0, 1));

	return (0);
}

void	*get_null(void)
{
	return (NULL);
}
