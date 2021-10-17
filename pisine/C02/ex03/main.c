#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	*str;

	str = "1234391283?21739";
	printf("%d\n", ft_str_is_numeric(str));
	return (0);
}
