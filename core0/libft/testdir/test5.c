#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	for (int i = -256; i < 256; ++i)
	{
		printf("%d %d %d\n", i, toupper(i), ft_toupper(i));
		printf("%d %d %d\n\n", i, tolower(i), ft_tolower(i));
	}
	return (0);
}
