#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	*str;

	str = "ABC";
	printf("%d\n", ft_str_is_uppercase(str));
	return (0);
}
