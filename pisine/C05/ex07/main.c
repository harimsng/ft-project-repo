#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	int		magic_num;

	magic_num = 46340 * 46340;
	printf("%d\n", ft_find_next_prime(magic_num));
	printf("%d\n", ft_find_next_prime(9839));
	printf("%d\n", ft_find_next_prime(9841));
	printf("%d\n", ft_find_next_prime(9843));
	printf("%d\n", ft_find_next_prime(9845));
	printf("%d\n", ft_find_next_prime(9847));
	printf("%d\n", ft_find_next_prime(9849));
	printf("%d\n", ft_find_next_prime(9851));
	printf("%d\n", ft_find_next_prime(2147483646));
	printf("%d\n", ft_find_next_prime(2147483647));
	return (0);
}
