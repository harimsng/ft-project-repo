#include <unistd.h>

int	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}
