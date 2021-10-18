#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int		*ptr;
	int		idx;
	int		min, max;

	min = -23, max = 33;
	idx = 0;
	ptr	= ft_range(min, max);
	while (idx < max - min)
		printf("%d ", ptr[idx++]);
	free(ptr);
	return (0);
}
