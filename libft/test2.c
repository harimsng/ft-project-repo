#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
	for (int i = -10; i < 100; ++i)
		printf("%d %d %d\n", i, ft_isalpha(i), isalpha(i));
	printf("\n");
	for (int i = -10; i < 100; ++i)
		printf("%d %d %d\n", i, ft_isalpha(i), isalpha(i));

/*	for (int i = -65536; i < 65536; ++i)
	{
		if (strchr("0123456789", i) != ft_strchr("0123456789", i))
			printf("%d %p %p\n", i, strchr("0123456789", i), ft_strchr("0123456789", i));
		if (strrchr("0123456789", i) != ft_strrchr("0123456789", i))
			printf("%d %p %p\n\n", i, strrchr("0123456789", i), ft_strrchr("0123456789", i));
	}
*/	return (0);
}
