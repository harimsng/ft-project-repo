#include <stdio.h>

int	ft_is_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2147483645));
	printf("%d\n", ft_is_prime(2147483629));
	printf("%d\n", ft_is_prime(2147483587));
	printf("%d\n", ft_is_prime(2147483579));
	printf("%d\n", ft_is_prime(2147483563));
	printf("%d\n", ft_is_prime(2147483489));
	printf("%d\n", ft_is_prime(2147483491));
	printf("%d\n", ft_is_prime(2147));
	printf("%d\n", ft_is_prime(2149));
	printf("%d\n", ft_is_prime(2151));
	printf("%d\n", ft_is_prime(2153));
	printf("%d\n", ft_is_prime(2155));
	printf("%d\n", ft_is_prime(-5));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	return (0);
}
