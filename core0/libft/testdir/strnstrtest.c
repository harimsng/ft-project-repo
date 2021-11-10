#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*s1 = "121231212123";
	char	*s2 = "1212123";

	printf("%s\n", ft_strnstr(s1, s2, 12)); 
	return (0);
}
