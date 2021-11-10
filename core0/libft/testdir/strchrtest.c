#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str = "";

	printf("%p\n", strchr(str, 0));
	printf("%p\n", ft_strchr(str, 0));
	printf("%p\n", strrchr(str, 0));
	printf("%p\n", ft_strrchr(str, 0));
	return (0);
}
