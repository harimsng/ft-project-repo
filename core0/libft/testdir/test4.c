#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	buf[10] = {0, };

	ft_memset(buf, 'a', 3);
	printf("%zu\n", ft_strlcat(buf, "0123456789abcdef", 2));
	printf("%s\n", buf);
	return (0);
}
