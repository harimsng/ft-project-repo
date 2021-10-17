#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int		a;
	int		b;
	int		aa;
	int		bb;

	a = 42;
	b = 8;
	ft_div_mod(a, b, &aa, &bb);
	printf("%d %d %d %d\n", a, b, aa, bb);
	return (0);
}
