#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char	*str;

/*	str = ft_substr("0123456789", 5, 10);
	printf("|%s|\n", str);
	free(str);
	str = strdup(NULL);
	printf("%s\n", str);
	free(str);
*/
	str = ft_itoa(-2147483648);
	printf("|%s|\n", str);
	free(str);
	str = ft_itoa(2147483647);
	printf("|%s|\n", str);
	free(str);
	str = ft_itoa(-1000);
	printf("|%s|\n", str);
	free(str);
	str = ft_itoa(-3581357);
	printf("|%s|\n", str);
	free(str);
	str = ft_itoa(1024);
	printf("|%s|\n", str);
	free(str);

	return (0);
}
