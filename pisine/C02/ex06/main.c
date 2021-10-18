#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	str[10];
	int		idx;
	char	control;

	idx = 0;
	while (idx < 10)
	{
		str[idx] = 65 + idx;
		++idx;
	}
	str[0] = 127;
	printf("%s\n", str);
	printf("%d\n", ft_str_is_printable(str));
	control = 3;
	printf("_%c_\n", control);
	control = 127;
	printf("_%c_\n", control);
	return (0);
}
