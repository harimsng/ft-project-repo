#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str = "abcdefg1234567890";
	int		idx = 0;

	idx = -300;
	while (idx < 300)
	{
		printf("%p\n", strchr(str, idx));
		printf("%p\n", ft_strchr(str, idx));
		printf("%p\n", strrchr(str, idx));
		printf("%p\n", ft_strrchr(str, idx));
		++idx;
	}
	return (0);
}
