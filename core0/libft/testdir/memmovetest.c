#include "libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char		src[] = "lorem ipsum dolor sit amet";
	char		src2[] = "lorem ipsum dolor sit amet";
	char		*dest, *dest2;

	dest = src + 1;
	dest2 = src2 + 1;
	printf("%s\n", (char *)memmove(dest, src, 8));
	printf("%s\n", src);
	printf("\n%s\n", (char *)ft_memmove(dest2, src2, 8));
	printf("%s\n", src2); 
}
