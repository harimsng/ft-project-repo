#include <stdio.h>

char	*ft_strlowercase(char *str);

int	main(void)
{
	char	str[10];
	int		idx;

	idx = 0;
	while (idx < 10)
	{
		str[idx] = 'A' + idx;
		++idx;
	}
	printf("%s\n", str);
	ft_strlowercase(str);
	printf("%s\n", str);
	return (0);
}
