#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	printf("%d %d\n", strncmp("123a", "123A", 5), ft_strncmp("123a", "123A", 5));
	printf("%d %d\n", strncmp("123a", "123A", 3), ft_strncmp("123a", "123A", 3));
	printf("%d %d\n", strncmp("a", "", 5), ft_strncmp("a", "", 5));
	printf("%d %d\n", strncmp("", "a", 5), ft_strncmp("", "a", 5));

	return (0);
}
