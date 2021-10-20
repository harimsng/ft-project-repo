#include "ft.h"

#include <stdio.h>

int	main(void)
{
	int		a;
	int		b;

	ft_putchar('4');
	ft_putchar('2');
	ft_putchar('\n');
	a = 2;
	b = 4;
	ft_putchar(48 + a);
	ft_putchar(48 + b);
	ft_putchar('\n');
	ft_swap(&a, &b);
	ft_putchar(48 + a);
	ft_putchar(48 + b);
	ft_putchar('\n');
	ft_putstr("__42__\n");
	printf("%d\n", ft_strcmp("111\x7f", "111"));
	printf("%d\n", ft_strlen("1234567"));
	return (0);
}
