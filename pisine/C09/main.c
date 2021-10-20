#include "ft.h"
#include <stdio.h>

int	main(void)
{
	int		a;
	int		b;

	a = 2;
	b = 4;
	ft_putstr("Hello, library!\n");
	ft_putchar('4');
	ft_swap(&a, &b);
	printf("%d%d\n", a, b);
	printf("%d\n", ft_strcmp("\xff", "\x00"));
	printf("%d\n", ft_strlen("12345"));
	return (0);
}
