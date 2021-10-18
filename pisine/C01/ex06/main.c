#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	*str;
	int		len;

	str = "1234567890123456";
	len = ft_strlen(str);
	printf("%d\n", len);
	return (0);
}
