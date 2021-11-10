#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char	*str;

	str = ft_substr("tripouille", 100, 1);
	printf("|%s|\n", str);
	free(str);

/*	str = strdup(NULL);
	printf("%s\n", str);
	free(str);

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

	str = ft_strjoin("12345", "abcde");
	printf("|%s|\n", str);
	free(str);
	str = ft_strjoin("", "");
	printf("|%s|\n", str);
	free(str);
	str = ft_strjoin("1", "");
	printf("|%s|\n", str);
	free(str);
	str = ft_strjoin("", "a");
	printf("|%s|\n", str);
	free(str);

	str = ft_strtrim("1234567890", "24680");
	printf("|%s|\n", str);
	free(str);
	str = ft_strtrim("0a1b2c3d4e5f6g7h8i9j10k11l12m13n14o15p16q17r18s19t20u\
21v22w23x24y25z", "0123456789");
	printf("|%s|\n", str);
	free(str);
*/	return (0);
}
