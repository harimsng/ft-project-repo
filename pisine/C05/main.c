#include <stdio.h>

int	ft_iterative_sqrt(int nb);

int	main(void)
{
	printf("%d\n", ft_iterative_sqrt(-2));
	printf("%d\n", ft_iterative_sqrt(-1));
	printf("%d\n", ft_iterative_sqrt(0));
	printf("%d\n", ft_iterative_sqrt(1));
	printf("%d\n", ft_iterative_sqrt(4));
	printf("%d\n", ft_iterative_sqrt(16));
	printf("%d\n", ft_iterative_sqrt(46340 * 46340));
	printf("%d\n", ft_iterative_sqrt(2147483647));
	return (0);
}
