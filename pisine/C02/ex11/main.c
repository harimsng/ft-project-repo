#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str[256];
	int		idx;

	idx = 1;
	while (idx < 256)
	{
		str[idx - 1] = idx;
		++idx;
	}
	str[255] = 0;
	ft_putstr_non_printable(str);
	return (0);
}
