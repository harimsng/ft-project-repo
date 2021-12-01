#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str = "abcdef";

	printf("%p\n", ft_memchr(str, 'b', 1));
	printf("%p\n\n", memchr(str, 'b', 1));

	return (0);	
}
