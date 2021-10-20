#include <stdio.h>
#include "ft_abs.h"

int	main(void)
{
	int		num;

	num = -42;
	printf("%d\n", ABS(-42));
	printf("%d\n", ABS(num));
	printf("%d\n", ABS(-num));
	printf("%d\n", ABS(42));
	return (0);
}
