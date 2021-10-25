#include <unistd.h>

void	ft_puterr(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		++len;
	
	write(2, str, len);
}
