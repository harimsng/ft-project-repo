#include <unistd.h>

#include "ft_lib.h"

void	ft_putstr(char *str)
{
	if (str == 0)
		return ;
	while (*str != 0)
		write(1, str++, 1);
}

int	max_change(int *a, int b)
{
	if (*a < b)
	{
		*a = b;
		return (1);
	}
	return (0);
}	
