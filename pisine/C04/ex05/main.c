#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char	*str;
	char	*base;

	str = "  +--+--+-cbabbc";
	base = "abcd";
	printf("%d\n", ft_atoi_base(str, base));
	str = "  +--+--+-cbabbc";
	base = "abc ";
	printf("%d\n", ft_atoi_base(str, base));
	str = "  +--+--+-cbabbc";
	base = "abc+";
	printf("%d\n", ft_atoi_base(str, base));
	str = "  +--+--+-cbabbc";
	base = "ab-c";
	printf("%d\n", ft_atoi_base(str, base));
	str = "  +--+--+-cbabbc";
	base = "abbc";
	printf("%d\n", ft_atoi_base(str, base));
	str = " +--+--+-cbabbc";
	base = "abcde";
	printf("%d\n", ft_atoi_base(str, base));
	str = "  +--+--+-cbabbc";
	base = "abcdef";
	printf("%d\n", ft_atoi_base(str, base));
	return (0);
}
