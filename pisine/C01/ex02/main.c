#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int		n1;
	int		n2;

	n1 = 2;
	n2 = 4;
	printf("%d%d\n", n1, n2);
	ft_swap(&n1, &n2);
	printf("%d%d\n", n1, n2);
	return (0);
}
