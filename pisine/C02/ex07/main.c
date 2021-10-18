#include <stdio.h>

char*	ft_strupcase(char *str);

int	main(void)
{
	char	str[10];
	int		idx;

	idx = 0;
	while (idx < 10)
	{
		str[idx] = idx + 'a';
		++idx;
	}
	str[idx] = 0;
	str[3] -= 32;
	printf("%s\n", ft_strupcase(str));
	return (0);
}
