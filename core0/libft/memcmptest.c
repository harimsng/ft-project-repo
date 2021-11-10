#include "libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int		test1 = 1023 + 1024;
	int		test2 = 1023 - 512;
	printf("%d %d\n", memcmp(&test1, &test2, 4), ft_memcmp(&test1, &test2, 4));
	return (0);
}
